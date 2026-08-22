#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
    int count=0;
    int pivot=arr[s];
    for(int i=s+1;i<e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotindex=s+count;
    //now we put the pivot elemnt to its right place.
    swap(arr[s],arr[pivotindex]);
    //we put element greatrer than pivot to right and less than pivot to the left.
    int i=s;
    int j=e;
    while(i<pivotindex && j>pivotindex){
        while(pivot>=arr[i]){
            i++;
        }
        while(pivot<arr[j]){

            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;

}
void quick_sort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    //left side me sorting krenge.
    int p=partition(arr,s,e);
    quick_sort(arr,s,p-1);
    //right side sort krenge.
    quick_sort(arr,p+1,e);

}
int main(){
    int arr[7]={5,2,1,6,3,4,8};
    int n=7;
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}