#include<iostream>
using namespace std;
int binarysearch(int arr[],int target,int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(target==arr[mid]){
            return mid;
        }
        else if(target>arr[mid]){
            s=mid+1;
            
        }
        else{
            e=mid-1;
        }
        mid=s +(e-s)/2;
    }
    return s;

}
int main(){
    int arr[7]={10,20,30,40,50,60,70};
    int result=binarysearch(arr,30,7);
    cout<<result<<endl;
    return 0;
}