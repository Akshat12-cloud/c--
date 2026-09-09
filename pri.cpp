#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(j==n-i-1 || j==n+i-1 || (i==n/2 && j>n-i-1 && j<n+i-1)){
                cout<<"*";
            }
            else{
                cout<< " ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i && i<3 || j==n-i-1 && i<3 ||(i>=2 && j==2)){
                cout<<"*";

            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}