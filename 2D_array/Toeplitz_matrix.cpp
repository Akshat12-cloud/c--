#include<iostream>
#include<vector>
using namespace std;
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    if( n==1 || m==1){
        return true;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(matrix[i][j] !=matrix[i+1][j+1]){
                return false;
            }
        }
    }
    return true;
        
}
    
int main(){
    vector<vector<int>> arr={{1,2,3,4},{4,1,2,3},{5,4,1,2},{6,5,4,1},{7,6,5,7}} ;

    if(isToeplitzMatrix(arr)==true){
        cout<<"it is a toeplit matrix."<<endl;
    }
    else{
        cout<<"it is not a toeplitz matrix."<<endl;
    }
    
    return 0;
}