#include<iostream>
#include<vector>
using namespace std;
vector<int> findnumber(vector<int> &arr1,vector<int> &arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j]){
                ans.push_back(arr1[i]);
            }
        }
    }
    return ans;
}
vector<int> luckyno(vector<vector<int>> &arr){
    int row=arr.size();
    int col=arr[0].size();
    vector<int> arr1;
    vector<int> arr2;
    
    
    for(int i=0;i<row;i++){
        int min=arr[i][0];
        for(int j=0;j<col;j++){
            if(arr[i][j]<min){
                min=arr[i][j];
            }    
        }
        arr1.push_back(min);
    }
    for(int i=0;i<col;i++){
        int max=arr[0][i];
        for(int j=0;j<row;j++){
            if(arr[j][i]>max){
                max=arr[j][i];
            }
        }
        arr2.push_back(max);
    }
    return findnumber(arr1,arr2);
}
int main(){
    vector<vector<int>> arr={{10,11,12},{9,7,3},{15,18,20}};

    vector<int> result=luckyno(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    
    return 0;

}
