//finf duplicate element from the array.
#include<iostream>
using namespace std;
int finduplicate(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans^=arr[i];
    }
    for(int j=0;j<size;j++){

        ans=ans^j;
    }
    return ans;   

}
int main(){
    int arr[]={1,2,4,3,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int result=finduplicate(arr,size);
    cout<<"the duplicate element array in the array is :"<<result;
    return 0;
}