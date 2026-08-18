#include<iostream>
using namespace std;
int arraysum(int arr[],int size){
    if(size==0 ){
        return 0;
    }
    if(size==1){
        
        return arr[0];
        
    }
    else{
        
        int sum= arr[0]+ arraysum(arr+1,size-1);
        return sum;
    }

}
int main(){
    int arr[5]={2,3,4,5,6};
    int n=5;
    int result=arraysum(arr,n);
    cout<<result<<endl;
    return 0;
}