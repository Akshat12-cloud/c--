// Q...Find the sum of each row.
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int arr[100][100];

    // Input matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Calculate row sums
    for (int i = 0; i < rows; i++) {
        int sum = 0;

        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }

        cout << "Row " << i + 1 << " Sum = " << sum << endl;
    }

    return 0;
}
