#include <stdio.h>

#define MAX_PROCESSES 50
#define MAX_BLOCKS 50

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int waiting;
    int turnaround;
    int response;
    int started;
    int remaining;
} Process;

typedef struct {
    int id;
    int size;
    int allocated;
    int processId;
} MemoryBlock;

Process processes[MAX_PROCESSES];
int processCount = 0;

MemoryBlock memoryBlocks[MAX_BLOCKS];
int blockCount = 0;


/* ---------- MEMORY TOTAL ---------- */

int totalMemory(MemoryBlock b[], int nb)
{
    int total = 0;

    for (int i = 0; i < nb; i++)
    {
        total += b[i].size;
    }

    return total;
}


/* ---------- RESET SCHEDULING RESULTS ---------- */

void resetResults(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].completion = 0;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        p[i].response = -1;
        p[i].started = 0;
        p[i].remaining = p[i].burst;
    }
}


/* ---------- CREATE PROCESSES ---------- */

void createProcesses()
{
    int n;

    printf("\nEnter number of processes (1-%d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n < 1 || n > MAX_PROCESSES)
    {
        printf("Invalid number of processes.\n");
        return;
    }

    processCount = n;

    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;

        printf("\nProcess P%d\n", processes[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &processes[i].burst);

        printf("Priority (smaller number = higher priority): ");
        scanf("%d", &processes[i].priority);
    }

    resetResults(processes, processCount);

    printf("\nProcesses created successfully.\n");
}


/* ---------- DISPLAY PROCESSES ---------- */

void displayProcesses()
{
    if (processCount == 0)
    {
        printf("\nNo processes created yet.\n");
        return;
    }

    printf("\n%-8s %-10s %-8s %-10s\n",
           "PID", "Arrival", "Burst", "Priority");

    for (int i = 0; i < processCount; i++)
    {
        printf("%-8d %-10d %-8d %-10d\n",
               processes[i].pid,
               processes[i].arrival,
               processes[i].burst,
               processes[i].priority);
    }
}


/* ---------- PRINT SCHEDULING RESULTS ---------- */

void printSchedulingResults(Process p[], int n, const char *name)
{
    double totalWaiting = 0;
    double totalTurnaround = 0;
    double totalResponse = 0;
    int lastCompletion = 0;

    printf("\n========== %s ==========\n", name);

    printf("%-6s %-8s %-8s %-12s %-10s %-12s %-10s\n",
           "PID", "AT", "BT", "Completion",
           "Waiting", "Turnaround", "Response");

    for (int i = 0; i < n; i++)
    {
        printf("%-6d %-8d %-8d %-12d %-10d %-12d %-10d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].waiting,
               p[i].turnaround,
               p[i].response);

        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;
        totalResponse += p[i].response;

        if (p[i].completion > lastCompletion)
        {
            lastCompletion = p[i].completion;
        }
    }

    printf("\nAverage Waiting Time    : %.2f\n",
           totalWaiting / n);

    printf("Average Turnaround Time : %.2f\n",
           totalTurnaround / n);

    printf("Average Response Time   : %.2f\n",
           totalResponse / n);

    if (lastCompletion > 0)
    {
        int totalBurst = 0;

        for (int i = 0; i < n; i++)
        {
            totalBurst += p[i].burst;
        }

        printf("CPU Utilization         : %.2f%%\n",
               ((double)totalBurst / lastCompletion) * 100.0);
    }
}


/* ---------- FCFS ---------- */

void fcfs(Process p[], int n)
{
    resetResults(p, n);

    Process temp[MAX_PROCESSES];

    for (int i = 0; i < n; i++)
    {
        temp[i] = p[i];
    }

    /* Sort according to Arrival Time */

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (temp[j].arrival > temp[j + 1].arrival)
            {
                Process x = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = x;
            }
        }
    }

    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time < temp[i].arrival)
        {
            time = temp[i].arrival;
        }

        temp[i].response = time - temp[i].arrival;

        time += temp[i].burst;

        temp[i].completion = time;

        temp[i].turnaround =
            temp[i].completion - temp[i].arrival;

        temp[i].waiting =
            temp[i].turnaround - temp[i].burst;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i].pid == temp[j].pid)
            {
                p[i] = temp[j];
                break;
            }
        }
    }

    printSchedulingResults(p, n, "FCFS");
}


/* ---------- SJF ---------- */

void sjf(Process p[], int n)
{
    resetResults(p, n);

    int completed = 0;
    int time = 0;

    while (completed < n)
    {
        int index = -1;
        int shortest = 1000000000;

        for (int i = 0; i < n; i++)
        {
            if (p[i].completion == 0 &&
                p[i].arrival <= time &&
                p[i].burst < shortest)
            {
                shortest = p[i].burst;
                index = i;
            }
        }

        if (index == -1)
        {
            int nextArrival = 1000000000;

            for (int i = 0; i < n; i++)
            {
                if (p[i].completion == 0 &&
                    p[i].arrival < nextArrival)
                {
                    nextArrival = p[i].arrival;
                }
            }

            time = nextArrival;
            continue;
        }

        p[index].response =
            time - p[index].arrival;

        time += p[index].burst;

        p[index].completion = time;

        p[index].turnaround =
            p[index].completion - p[index].arrival;

        p[index].waiting =
            p[index].turnaround - p[index].burst;

        completed++;
    }

    printSchedulingResults(p, n, "SJF (Non-Preemptive)");
}


/* ---------- PRIORITY ---------- */

void priorityScheduling(Process p[], int n)
{
    resetResults(p, n);

    int completed = 0;
    int time = 0;

    while (completed < n)
    {
        int index = -1;
        int bestPriority = 1000000000;

        for (int i = 0; i < n; i++)
        {
            if (p[i].completion == 0 &&
                p[i].arrival <= time &&
                p[i].priority < bestPriority)
            {
                bestPriority = p[i].priority;
                index = i;
            }
        }

        if (index == -1)
        {
            int nextArrival = 1000000000;

            for (int i = 0; i < n; i++)
            {
                if (p[i].completion == 0 &&
                    p[i].arrival < nextArrival)
                {
                    nextArrival = p[i].arrival;
                }
            }

            time = nextArrival;
            continue;
        }

        p[index].response =
            time - p[index].arrival;

        time += p[index].burst;

        p[index].completion = time;

        p[index].turnaround =
            p[index].completion - p[index].arrival;

        p[index].waiting =
            p[index].turnaround - p[index].burst;

        completed++;
    }

    printSchedulingResults(p, n, "Priority Scheduling");
}


/* ---------- ROUND ROBIN ---------- */

void roundRobin(Process p[], int n, int quantum)
{
    resetResults(p, n);

    int queue[MAX_PROCESSES * 100];
    int front = 0;
    int rear = 0;

    int added[MAX_PROCESSES] = {0};

    int completed = 0;
    int time = 0;

    int firstArrival = p[0].arrival;

    for (int i = 1; i < n; i++)
    {
        if (p[i].arrival < firstArrival)
        {
            firstArrival = p[i].arrival;
        }
    }

    time = firstArrival;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!added[i] &&
                p[i].arrival <= time)
            {
                queue[rear++] = i;
                added[i] = 1;
            }
        }

        if (front == rear)
        {
            int nextArrival = 1000000000;

            for (int i = 0; i < n; i++)
            {
                if (!added[i] &&
                    p[i].arrival < nextArrival)
                {
                    nextArrival = p[i].arrival;
                }
            }

            time = nextArrival;
            continue;
        }

        int index = queue[front++];

        if (p[index].response == -1)
        {
            p[index].response =
                time - p[index].arrival;
        }

        int runTime;

        if (p[index].remaining < quantum)
        {
            runTime = p[index].remaining;
        }
        else
        {
            runTime = quantum;
        }

        p[index].remaining -= runTime;

        time += runTime;

        for (int i = 0; i < n; i++)
        {
            if (!added[i] &&
                p[i].arrival <= time)
            {
                queue[rear++] = i;
                added[i] = 1;
            }
        }

        if (p[index].remaining > 0)
        {
            queue[rear++] = index;
        }
        else
        {
            p[index].completion = time;

            p[index].turnaround =
                p[index].completion - p[index].arrival;

            p[index].waiting =
                p[index].turnaround - p[index].burst;

            completed++;
        }
    }

    printSchedulingResults(p, n, "Round Robin");
}


/* ---------- CPU MENU ---------- */

void schedulingMenu()
{
    if (processCount == 0)
    {
        printf("\nPlease create processes first.\n");
        return;
    }

    int choice;

    do
    {
        printf("\n========== CPU SCHEDULING ==========\n");
        printf("1. FCFS\n");
        printf("2. SJF (Non-Preemptive)\n");
        printf("3. Priority Scheduling\n");
        printf("4. Round Robin\n");
        printf("5. Run All Algorithms\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            fcfs(processes, processCount);
        }
        else if (choice == 2)
        {
            sjf(processes, processCount);
        }
        else if (choice == 3)
        {
            priorityScheduling(processes, processCount);
        }
        else if (choice == 4)
        {
            int quantum;

            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);

            if (quantum <= 0)
            {
                printf("Time quantum must be greater than 0.\n");
            }
            else
            {
                roundRobin(processes,
                           processCount,
                           quantum);
            }
        }
        else if (choice == 5)
        {
            int quantum;

            printf("\nEnter Time Quantum for Round Robin: ");
            scanf("%d", &quantum);

            if (quantum <= 0)
            {
                printf("Invalid quantum.\n");
            }
            else
            {
                fcfs(processes, processCount);
                sjf(processes, processCount);
                priorityScheduling(processes, processCount);
                roundRobin(processes,
                           processCount,
                           quantum);
            }
        }
        else if (choice != 0)
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 0);
}


/* =========================================================
                     MEMORY MANAGEMENT
   ========================================================= */


/* ---------- CREATE MEMORY BLOCKS ---------- */

void createMemoryBlocks()
{
    int n;

    printf("\nEnter number of memory blocks (1-%d): ",
           MAX_BLOCKS);

    scanf("%d", &n);

    if (n < 1 || n > MAX_BLOCKS)
    {
        printf("Invalid number of blocks.\n");
        return;
    }

    blockCount = n;

    for (int i = 0; i < n; i++)
    {
        memoryBlocks[i].id = i + 1;

        printf("Enter size of Block %d (KB): ",
               i + 1);

        scanf("%d", &memoryBlocks[i].size);

        if (memoryBlocks[i].size <= 0)
        {
            printf("Invalid size. Setting size to 1 KB.\n");
            memoryBlocks[i].size = 1;
        }

        memoryBlocks[i].allocated = 0;
        memoryBlocks[i].processId = -1;
    }

    printf("\nMemory blocks created successfully.\n");
}


/* ---------- DISPLAY MEMORY ---------- */

void displayMemory()
{
    if (blockCount == 0)
    {
        printf("\nNo memory blocks created.\n");
        return;
    }

    printf("\n========== MEMORY BLOCKS ==========\n");

    printf("%-8s %-12s %-12s %-12s\n",
           "Block",
           "Size(KB)",
           "Status",
           "Process");

    for (int i = 0; i < blockCount; i++)
    {
        if (memoryBlocks[i].allocated)
        {
            printf("%-8d %-12d %-12s P%-11d\n",
                   memoryBlocks[i].id,
                   memoryBlocks[i].size,
                   "Allocated",
                   memoryBlocks[i].processId);
        }
        else
        {
            printf("%-8d %-12d %-12s %-12s\n",
                   memoryBlocks[i].id,
                   memoryBlocks[i].size,
                   "Free",
                   "-");
        }
    }
}


/* ---------- FIRST FIT ---------- */

int allocateFirstFit(int request, int pid)
{
    for (int i = 0; i < blockCount; i++)
    {
        if (!memoryBlocks[i].allocated &&
            memoryBlocks[i].size >= request)
        {
            memoryBlocks[i].allocated = 1;
            memoryBlocks[i].processId = pid;

            return i;
        }
    }

    return -1;
}


/* ---------- BEST FIT ---------- */

int allocateBestFit(int request, int pid)
{
    int best = -1;

    for (int i = 0; i < blockCount; i++)
    {
        if (!memoryBlocks[i].allocated &&
            memoryBlocks[i].size >= request)
        {
            if (best == -1 ||
                memoryBlocks[i].size <
                memoryBlocks[best].size)
            {
                best = i;
            }
        }
    }

    if (best != -1)
    {
        memoryBlocks[best].allocated = 1;
        memoryBlocks[best].processId = pid;
    }

    return best;
}


/* ---------- WORST FIT ---------- */

int allocateWorstFit(int request, int pid)
{
    int worst = -1;

    for (int i = 0; i < blockCount; i++)
    {
        if (!memoryBlocks[i].allocated &&
            memoryBlocks[i].size >= request)
        {
            if (worst == -1 ||
                memoryBlocks[i].size >
                memoryBlocks[worst].size)
            {
                worst = i;
            }
        }
    }

    if (worst != -1)
    {
        memoryBlocks[worst].allocated = 1;
        memoryBlocks[worst].processId = pid;
    }

    return worst;
}


/* ---------- RESET MEMORY ---------- */

void resetMemoryAllocation()
{
    for (int i = 0; i < blockCount; i++)
    {
        memoryBlocks[i].allocated = 0;
        memoryBlocks[i].processId = -1;
    }
}


/* ---------- RUN MEMORY ALGORITHM ---------- */

void runMemoryAlgorithm(int algorithm)
{
    if (blockCount == 0)
    {
        printf("\nPlease create memory blocks first.\n");
        return;
    }

    int requests[MAX_PROCESSES];
    int requestCount;

    printf("\nEnter number of memory requests: ");
    scanf("%d", &requestCount);

    if (requestCount < 1 ||
        requestCount > MAX_PROCESSES)
    {
        printf("Invalid number of requests.\n");
        return;
    }

    for (int i = 0; i < requestCount; i++)
    {
        printf("Request size for Process P%d (KB): ",
               i + 1);

        scanf("%d", &requests[i]);

        if (requests[i] <= 0)
        {
            printf("Invalid request. Setting it to 1 KB.\n");
            requests[i] = 1;
        }
    }

    /* Start a fresh allocation */

    resetMemoryAllocation();

    printf("\n========== MEMORY ALLOCATION ==========\n");

    for (int i = 0; i < requestCount; i++)
    {
        int index = -1;

        if (algorithm == 1)
        {
            index =
                allocateFirstFit(requests[i], i + 1);
        }
        else if (algorithm == 2)
        {
            index =
                allocateBestFit(requests[i], i + 1);
        }
        else if (algorithm == 3)
        {
            index =
                allocateWorstFit(requests[i], i + 1);
        }

        if (index != -1)
        {
            printf("P%d (%d KB) -> Block %d (%d KB)\n",
                   i + 1,
                   requests[i],
                   memoryBlocks[index].id,
                   memoryBlocks[index].size);
        }
        else
        {
            printf("P%d (%d KB) -> Allocation Failed\n",
                   i + 1,
                   requests[i]);
        }
    }

    displayMemory();

    int total =
        totalMemory(memoryBlocks, blockCount);

    int allocated = 0;

    for (int i = 0; i < blockCount; i++)
    {
        if (memoryBlocks[i].allocated)
        {
            allocated += memoryBlocks[i].size;
        }
    }

    if (total > 0)
    {
        printf("\nMemory Utilization: %.2f%%\n",
               ((double)allocated / total) * 100.0);
    }
}


/* ---------- COMPARE MEMORY ALGORITHMS ---------- */

void compareMemoryAlgorithms()
{
    if (blockCount == 0)
    {
        printf("\nPlease create memory blocks first.\n");
        return;
    }

    int requests[MAX_PROCESSES];
    int requestCount;

    printf("\nEnter number of memory requests: ");
    scanf("%d", &requestCount);

    if (requestCount < 1 ||
        requestCount > MAX_PROCESSES)
    {
        printf("Invalid number of requests.\n");
        return;
    }

    for (int i = 0; i < requestCount; i++)
    {
        printf("Request size for Process P%d (KB): ",
               i + 1);

        scanf("%d", &requests[i]);
    }

    const char *names[] =
    {
        "First Fit",
        "Best Fit",
        "Worst Fit"
    };

    for (int algorithm = 1;
         algorithm <= 3;
         algorithm++)
    {
        resetMemoryAllocation();

        int success = 0;

        printf("\n--- %s ---\n",
               names[algorithm - 1]);

        for (int i = 0; i < requestCount; i++)
        {
            int index = -1;

            if (algorithm == 1)
            {
                index =
                    allocateFirstFit(requests[i], i + 1);
            }
            else if (algorithm == 2)
            {
                index =
                    allocateBestFit(requests[i], i + 1);
            }
            else
            {
                index =
                    allocateWorstFit(requests[i], i + 1);
            }

            if (index != -1)
            {
                printf("P%d -> Block %d\n",
                       i + 1,
                       memoryBlocks[index].id);

                success++;
            }
            else
            {
                printf("P%d -> Failed\n", i + 1);
            }
        }

        printf("Successful Allocations: %d/%d\n",
               success,
               requestCount);
    }

    resetMemoryAllocation();

    printf("\nMemory state reset to all FREE "
           "after comparison.\n");
}


/* ---------- REAL DEALLOCATION ---------- */

void deallocateMemory()
{
    if (blockCount == 0)
    {
        printf("\nPlease create memory blocks first.\n");
        return;
    }

    int blockId;

    displayMemory();

    printf("\nEnter Block ID to deallocate: ");
    scanf("%d", &blockId);

    if (blockId < 1 ||
        blockId > blockCount)
    {
        printf("Invalid Block ID.\n");
        return;
    }

    int index = blockId - 1;

    if (!memoryBlocks[index].allocated)
    {
        printf("\nBlock %d is already FREE.\n",
               blockId);
        return;
    }

    printf("\nBlock %d containing P%d "
           "has been deallocated.\n",
           memoryBlocks[index].id,
           memoryBlocks[index].processId);

    /* REAL DEALLOCATION */

    memoryBlocks[index].allocated = 0;
    memoryBlocks[index].processId = -1;

    printf("\nUpdated Memory Status:\n");

    displayMemory();
}


/* ---------- MEMORY MENU ---------- */

void memoryMenu()
{
    int choice;

    do
    {
        printf("\n========== MEMORY MANAGEMENT ==========\n");

        printf("1. Create / Replace Memory Blocks\n");
        printf("2. Display Memory Blocks\n");
        printf("3. First Fit Allocation\n");
        printf("4. Best Fit Allocation\n");
        printf("5. Worst Fit Allocation\n");
        printf("6. Compare All Algorithms\n");
        printf("7. Deallocate Memory Block\n");
        printf("8. Reset All Allocations\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createMemoryBlocks();
                break;

            case 2:
                displayMemory();
                break;

            case 3:
                runMemoryAlgorithm(1);
                break;

            case 4:
                runMemoryAlgorithm(2);
                break;

            case 5:
                runMemoryAlgorithm(3);
                break;

            case 6:
                compareMemoryAlgorithms();
                break;

            case 7:
                deallocateMemory();
                break;

            case 8:
                resetMemoryAllocation();

                printf("\nAll memory blocks are now FREE.\n");
                break;

            case 0:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}


/* ---------- SAVE REPORT ---------- */

void saveReport()
{
    FILE *file =
        fopen("scheduling_report.txt", "w");

    if (file == NULL)
    {
        printf("\nUnable to create report file.\n");
        return;
    }

    fprintf(file,
            "CPU SCHEDULING & MEMORY MANAGEMENT SIMULATOR\n");

    fprintf(file,
            "============================================\n\n");

    fprintf(file,
            "NUMBER OF PROCESSES: %d\n\n",
            processCount);

    if (processCount > 0)
    {
        fprintf(file, "PROCESS DETAILS\n");

        fprintf(file,
                "PID\tArrival\tBurst\tPriority\n");

        for (int i = 0;
             i < processCount;
             i++)
        {
            fprintf(file,
                    "P%d\t%d\t%d\t%d\n",
                    processes[i].pid,
                    processes[i].arrival,
                    processes[i].burst,
                    processes[i].priority);
        }
    }

    fprintf(file,
            "\nMEMORY BLOCKS: %d\n",
            blockCount);

    for (int i = 0;
         i < blockCount;
         i++)
    {
        fprintf(file,
                "Block %d: %d KB - %s",
                memoryBlocks[i].id,
                memoryBlocks[i].size,
                memoryBlocks[i].allocated
                    ? "Allocated"
                    : "Free");

        if (memoryBlocks[i].allocated)
        {
            fprintf(file,
                    " to P%d",
                    memoryBlocks[i].processId);
        }

        fprintf(file, "\n");
    }

    fprintf(file,
            "\nCPU Scheduling Algorithms:\n");
    fprintf(file, "1. FCFS\n");
    fprintf(file, "2. SJF (Non-Preemptive)\n");
    fprintf(file, "3. Priority Scheduling\n");
    fprintf(file, "4. Round Robin\n");

    fprintf(file,
            "\nMemory Management Algorithms:\n");
    fprintf(file, "1. First Fit\n");
    fprintf(file, "2. Best Fit\n");
    fprintf(file, "3. Worst Fit\n");
    fprintf(file, "4. Memory Deallocation\n");

    fclose(file);

    printf("\nReport saved successfully as "
           "scheduling_report.txt\n");
}


/* ---------- MAIN ---------- */

int main()
{
    int choice;

    printf("============================================\n");
    printf(" CPU SCHEDULING & MEMORY MANAGEMENT SIMULATOR\n");
    printf("============================================\n");

    do
    {
        printf("\n============== MAIN MENU ==============\n");

        printf("1. Create / Replace Processes\n");
        printf("2. Display Processes\n");
        printf("3. CPU Scheduling\n");
        printf("4. Memory Management\n");
        printf("5. Save Report\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createProcesses();
                break;

            case 2:
                displayProcesses();
                break;

            case 3:
                schedulingMenu();
                break;

            case 4:
                memoryMenu();
                break;

            case 5:
                saveReport();
                break;

            case 0:
                printf("\nProgram closed.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}