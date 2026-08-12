#include<iostream>

using namespace std;
int evenelement(int arr[],int n){
    int cnt=0;    
    for(int i=0;i<n;i++){
        int count=0;
        while(arr[i]>0){
        arr[i]=arr[i]/10;
        count++;

        }
        if(count%2==0){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int arr[7]={10,103,55,709,1000,999,178};
    int result=evenelement(arr,7);
    cout<<"the number of even character element in the array is :"<<result<<endl;
    return 0;
}
