#include<iostream>
using namespace std;
void triplates(int arr[],int size,int sum){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for (int k=j+1;k<size ;k++){
                if(arr[i]+arr[j]+arr[k]==sum){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                }
            }
        }
    }
}
int main(){

    int arr[]={1,2,5,7,3,9,4,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum;
    cout<<"enter the sum of number :";
    cin>>sum;
    triplates(arr,size,sum);
    return 0;
}

