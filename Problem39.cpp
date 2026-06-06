//Rotate array.
#include<iostream>
#include<vector>
using namespace std;
void rotatearray(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> temp(arr.size());
    for(int i=0;i<n;i++){
        temp[(i+k) %n]=arr[i];
    }
    arr=temp;
}



void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    rotatearray(arr,2);
    print(arr);
    return 0;
}