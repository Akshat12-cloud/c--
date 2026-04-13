//swap alternate element.
#include<iostream>

void reverse(int arr[],int size){
    int i=0;
    int temp;
    
    for(int j=1;j<size;j+=2){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i+=2;
    }
    
}
void reversearray(int arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    reverse(arr,6);
    reversearray(arr,6);

    return 0;
}