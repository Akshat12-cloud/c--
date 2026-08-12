//number of mismatch element in an sorted array.
#include<iostream>
using namespace std;
int mismatch(int arr[],int n){
    int cnt=0;
    int i=0; 
    while(i<n){  
        if(arr[i]>=arr[i-1] && arr[i]<=arr[i+1]){
         i++;
        }
        else{
            cnt++;
            i++;
        }
    }
    return cnt;
}
int main(){
    int arr1[9]={1,1,2,1,3,1,5,6,2};
    
    int result=mismatch(arr1,9);
    cout<<result<<endl;
    return 0;
}