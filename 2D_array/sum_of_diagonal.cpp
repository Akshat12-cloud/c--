//sum all the diagonal elemnet of the matrix.
#include<iostream>
using namespace std;
int diagonalsum(int arr[][3],int row,int col){
    int sum=0;
    for(int i=0;i<row;i++){
        sum+=arr[i][i];
        sum+=arr[i][row-1-i];
    }
    return sum;


}
int main(){
    int arr[3][3]={{7,8,9},{4,5,6},{1,2,3}};
    int result=diagonalsum(arr,3,3);
    cout<<result<<endl;
    return 0;
}