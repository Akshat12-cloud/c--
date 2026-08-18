//print 2d array.
#include<iostream>
using namespace std;
void print(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
    }


}
int main(){
    int arr[3][3]={{7,8,9},{4,5,6},{1,2,3}};
    print(arr,3,3);
    return 0;
}