//Reverse an array.
#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    int start=0;
    int end=size-1;
    while (start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void printarray(int arr[],int size){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<< endl;
}
int main(){
    int arr[]={1,3,2,5,7,8,3,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,size);
    printarray(arr,size);
    return 0;
}

