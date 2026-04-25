//selection sort.
#include<iostream>
using namespace std;

void selectionsort(int arr[],int size){
    for (int i=0;i<(size-1);i++){
        int minindex=i;
        for (int j=i+1;j<size;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }


        }
        swap(arr[minindex],arr[i]);

    }
    
    
}
int main(){
    int arr[]={44,31,27,30,76,12,10};
    int size =sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,size);
    cout<<"the sorted array is :";
    for (int k=0;k<size;k++){
        cout<<arr[k]<<" ";

    }
    return 0; 




}