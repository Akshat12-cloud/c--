#include<iostream>
void sort(int arr[],int size);
int main(){
    int arr[]={10,8,5,4,6,2,1,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    sort(arr,size);
    for (int element:arr){
        std::cout<<element<<" ";
    }
}
void sort(int arr[],int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            } 
        }
        
    }
}
