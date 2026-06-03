//insertion sort.
#include<iostream>
using namespace std;
void insertionsort(int arr[],int size){
    for (int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){ 
                arr[j+1]=arr[j];
            }
            else{
                break;
            }

        }
        arr[j+1]=temp;
    }
}
int printarray(int arr[],int size){
    for(int k=0;k<size;k++){
        cout<< arr[k]<<" ";

    }
    cout<<endl;
}


int main(){
    int arr[]={2,4,3,7,10,32,15,71,66};
    int size= sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,size);
    printarray(arr,size);
    return 0;
}