#include<iostream>
using namespace std;
bool binarysearch(int arr[],int s,int e,int key){
    int mid=s+(e-s)/2;
    if(s>e){
        return false;
    }
    if(key==arr[mid]){
        return true;
    }
    else if(key>arr[mid]){
        return binarysearch(arr,mid+1,e,key);
    }
    else{
        return binarysearch(arr,s,mid-1,key);
    }
    
}
int main(){
    int arr[8]={2,4,5,7,9,10,14,15};
    int n=8;
    int key=16;
    int ans=binarysearch(arr,0,n-1,key);
    if(ans==true){
            cout<<"found"<<endl;
        }
        else{
            cout<<"not found"<<endl;
        } 
    return 0;
}