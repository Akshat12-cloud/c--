//find pivot element of an array.
#include<iostream>
using namespace std;
int findpivot(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if (arr[mid]>=arr[0]){
            s=mid +1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main(){
    int arr[]={3,8,10,17,1};
    int size =sizeof(arr)/sizeof(arr[0]);
    int pivot=findpivot(arr,size);
    cout<<"the index of the pivot element is :"<<pivot;
    return 0;
}