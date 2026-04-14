#include<iostream>
using namespace std;
void sorting(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }

    }   
}
}
int main(){
    int arr[]={1,0,0,1,0,1,0,0,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    sorting(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}