//swap alternate element.
#include<iostream>
using namespace std;
void revalternate(int arr[],int size){
    int first=0;
    int second=1;
    while (second<size){
        swap(arr[first],arr[second]);
        first=first+2;
        second=second+2;
    }
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<< endl;
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    revalternate(arr,size);
    printarray(arr,size);
    return 0;
}