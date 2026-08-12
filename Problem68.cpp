//find next greatest element of the given array.
#include<iostream>
#include<vector>
using namespace std;
vector<int> greatestelement(vector<int> &arr){
    int n=arr.size();
    int maxi=-1;
    vector<int> temp(n);
    
    
    
    for(int i=n-1;i>=0;i--){
        temp[i]=maxi;      
        maxi=max(arr[i],maxi); 
        
        
    }
    
    return temp;

}
int main(){
    vector<int> arr={9,8,7,10,11,12,5,4,3,2};
    vector<int> result=greatestelement(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";

    }
    return 0;
}