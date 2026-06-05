//Reverse an array.
#include<iostream>
#include<vector>
using namespace std;
vector<int> reversearray(vector<int> &arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(arr[s++],arr[e--]);
    }cout<<endl;
    return arr;
}
void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    vector<int> arr;
    arr.push_back(11);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(12);
    arr.push_back(4);
    for(int i=0;i<5;i++){
        cout<< arr[i]<<" ";
    }cout<<endl;
    vector <int> ans= reversearray(arr);
    print(ans);
    return 0;
}