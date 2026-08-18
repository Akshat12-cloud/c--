//linear search.
#include<iostream>
using namespace std;
bool linearsearch(int arr[],int n,int key){
    if(n==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        bool ans=linearsearch(arr+1,n-1,key);
        return ans;
        
    }
}
int main(){
    int arr[5]={2,4,5,7,9};
    int n=5;
    int key=5;
    int ans=linearsearch(arr,n,key);
    if(ans==true){
            cout<<"found"<<endl;
        }
        else{
            cout<<"not found"<<endl;
        } 
    return 0;
}