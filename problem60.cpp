// largest row sum.
#include<iostream>
#include<climits>
using namespace std;
int rowsum(int arr[][4],int row ,int col){
    int maxi=INT_MIN;
    int rowindex=-1;
    
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        if(sum>maxi){
            maxi=sum;
            rowindex=row;
        }

    }
    cout<<"the maximum sum row is :"<<maxi<<endl;
    return rowindex;
}
int main(){
    int arr[3][4]={{1,2,3,4},{2,4,6,8},{3,7,9,10}};
    int result=rowsum(arr,3,4);
    cout<<result<<endl;
    return 0;
}