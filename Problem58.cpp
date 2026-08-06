// maximum sum of the sub array.
#include<iostream>
using namespace std;
int maxsubarray(int arr[],int n){
    int sum=0;
    int max=arr[0];
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum>=max){
            max=sum;
        }
        else if(sum<0){
            max=0;
        }

    }
    return max;


}
int main(){
    int arr[7]={2,5,10,-5,-10};
    int result=maxsubarray(arr,7);
    cout<<"the max sum is :"<<result<<endl;
    return 0;
}