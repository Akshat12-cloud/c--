//find unique elemnt in the array.
#include<iostream>
using namespace std;
int findunique(int arr[],int size){
    
    int result=0;
    for(int i=0;i<size;i++){
        result=result^arr[i];
    }
    return result;

}

int main(){
    int arr[]={2,3,4,5,3,4,5,6,7,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int output=findunique(arr,size);
    cout<<"the unique element in array is:"<<output;
    return 0;

}