//binary search.
#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start + ((end-start)/2);
    while (start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start + ((end-start)/2);
    }
    return -1;

}
int main(){
    int arr[]={1,5,6,7,8,9,29,32};
    int size= sizeof(arr)/sizeof(arr[0]);
    int key=6;
    
    int index = binarysearch(arr,size,key);
    cout<<"the index of the key element is :"<<index<< endl;
    return 0;

}