#include<iostream>
using namespace std;
bool toepitsmatrix(int arr[][4],int row,int col){
    for(int i=0;i<(row-2);i++){
        for(int j=0;j<col-2;j++){
            if(arr[i][j]!=arr[i+1][j+1]){
                return false;
                break;
            }
        }       
    }
    return true;
}
int main(){
    int arr[5][4]={{1,2,3,4},{4,1,2,3},{5,4,1,2},{6,5,4,1},{7,6,5,7}};
    bool ans=toepitsmatrix(arr,5,4);
    if(ans==true){
        cout<<"it is"<<endl;
    }
    else{
        cout<<" not"<<endl;
    }
    return 0;
}