#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    int row=3;
    int col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int sum=0;
            for(int k=i-1;k<=i+1;k++){
                for(int l=j-1;l<=j+1;l++){
                    if(k>=0 && k<row && l>=0 && l<col){
                        sum+=arr[k][l];
                    }    
                }
            }
            cout<<sum<< " ";
            
        }
        
    }
    return 0;
}