#include<iostream>
using namespace std;
int firstoccurance(int arr[],int n,int t){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(t==arr[mid]){
            ans=mid;
            e=mid-1;
        }
        else if(t<arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;

}
int lastoccurance(int arr[],int n,int t){
    int s=0;
    int e=n-1;
    int mid=s+( e-s)/2;
    int ans=-1;
    while(s<=e){
        if(t==arr[mid]){
            ans=mid;
            s=mid+1;
        }
        else if(t<arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[15]={1,2,2,2,2,2,3,3,3,3,4,5,7,7,9};
    int target=2;
    
    int result=firstoccurance(arr,15,target);
    cout<<"the first occurance of the element :"<<result<<endl;
    int result2=lastoccurance(arr,15,target);
    cout<<"the last occurance of the element :"<<result2<<endl;
    return 0;

}
