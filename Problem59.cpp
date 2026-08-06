#include<iostream>
using namespace std;
void rowsum(int arr[][4],int row ,int col){
    
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }

}
int main(){
    int arr[3][4]={{1,2,3,4},{2,4,6,8},{3,7,9,10}};
    rowsum(arr,3,4);
    return 0;
}