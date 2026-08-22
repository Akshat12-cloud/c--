#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int s,int e){
    int mid= s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first= new int[len1];//for left arr.
    int *second=new int[len2];//for right arr.
    //copy arr left side in 1st array.
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    //copy arr right side in 2nd array.
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }
    //now we merge two sorted array...................................................
    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<=second[index2]){
            arr[k++]=first[index1++];

        }
        else{
            arr[k++]=second[index2++];
        }

    }
    while(index1<len1){
        arr[k++]=first[index1++];
    }  
    while(index2<len2){
        arr[k++]=second[index2++];
    }
    delete[] first;
    delete[] second; 


}
void mergesort(int arr[],int s,int e){
    //base case.
    if(s>=e){
        return;
    }
    int mid=s +(e-s)/2;
    //left prt sort karenge.
    mergesort(arr,s,mid);
    //right prt sort karenge.
    mergesort(arr,mid+1,e);
    //merge karenge.
    merge(arr,s,e);

}
int main(){
    int arr[7]={2,3,1,4,5,7,6};
    int n=7;
    int s=0;
    int e=n-1;
    mergesort(arr,s,e);
    cout<<"sorted array is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";

    }
    return 0;

}