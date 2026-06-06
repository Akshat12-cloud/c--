//check if array is sorted  and rotated.
#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> &arr){
    int n=arr.size();
    int count=0;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i])
            count++;
    }
    if(arr[n-1]>arr[0]){
        count++;
    }
    return count<=1;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    vector<int> arr1={8,2,3,4,5,6,7};
    vector<int> arr2={1,3,2,4,6,8,0,7};
    cout<<check(arr)<<endl;
    cout<<check(arr1)<<endl;
    cout<<check(arr2)<<endl;
    return 0;

}