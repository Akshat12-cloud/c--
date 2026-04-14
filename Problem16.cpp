//find duplicate element.
#include<iostream>
using namespace std;
void duplicate(int arr[],int size){
    for (int j=0;j<size;j++){
        for(int i=j+1;i<size;i++){
            if(arr[j]==arr[i] && j!=i){
               cout<<arr[j]<<" ";
                break;
            }
        }

    }


}
int main(){
    int arr[15]={1,1,2,3,4,4,3,2,5,7,8,7,9,8,9};
    cout<<"the duplicate element is:" ;
    duplicate(arr,15);
    return 0;
}