#include<iostream>
using namespace std;
void findpairs(int arr[],int size,int sum){
    for(int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==sum ){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }

    }
}


int main(){
    int arr[]={2,6,5,3,9,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum;
    cout<<"enter the sum of number :";
    cin>>sum;
    findpairs(arr,size,sum);
    cout<<endl;
    return 0;
} 