//move zeroes .
#include<iostream>
#include<vector>
using namespace std;
void movezeroes(vector<int> &arr){
    int n=arr.size();
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}
void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
}
int main(){
    vector<int> arr={2,0,1,0,3,0,9};
    movezeroes(arr);
    print(arr);
    return 0;

}