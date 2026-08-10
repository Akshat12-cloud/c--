//Move all zeroes to the end on an array.
#include<iostream>
#include<vector>
using namespace std;
vector<int> movezeroes(vector<int> &arr){
    int n=arr.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i] !=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}
int main(){
    vector<int> arr={12,3,4,5,0,5,0,6,0};
    movezeroes(arr);
    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

