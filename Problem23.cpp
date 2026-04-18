//find peak index in mountain array.
#include<iostream>
using namespace std;
int peakelement(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if (arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main(){
    int arr[]={4,5,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int peak=peakelement(arr,size);
    cout<<"the index of the peak element is :"<<peak;
    return 0;

}