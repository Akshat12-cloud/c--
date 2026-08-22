#include<iostream>
#include<vector>
using namespace std;
int luckycount(vector<int> & rowsum,vector<int> &colsum){
    int n=rowsum.size();
    int i=0;
    int count=0;
    while(i<n){
        if(rowsum[i]==colsum[i]){
            count++;
            i++;
        }
    }
    return count;
}
vector<int> luckynumber(vector<vector<int>> &arr){
    int row=arr.size();
    int col=arr[0].size();
    vector<int> rowsum;
    
    vector<int> colsum;
   
    for(int i=0;i<row;i++){
        int sumrow=0; 
        int sumcol=0; 
        for(int j=0;j<col;j++){
            sumrow+=arr[i][j];
            sumcol+=arr[j][i];
        }
        rowsum.push_back(sumrow);
        colsum.push_back(sumcol);
    }
    int result=luckycount(rowsum,colsum);
    
}
int main(){
    vector<vector<int>> arr ={{1,0,0},{0,1,0},{1,0,1}};
    int ans=luckynumber(arr);
}