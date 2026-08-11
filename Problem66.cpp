//find the maojrity element.
#include<iostream>
using namespace std;
int majorelement(int arr[],int n){
    int candidate=-1;
    int count=0;
    for(int i=0;i<n;i++){
        if(count==0){
            candidate=arr[i];

        }
        else if(candidate=arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if (arr[i]==candidate){
            cnt++;
        }
        
    }
    if(cnt>=n/2){
        return candidate;

    }
    else{
        return -1;
    }
}
int main(){
    int arr[17]={1,1,2,2,1,1,2,2,2,1,1,3,1,1,2,2,2};
    int result=majorelement(arr,17);
    cout<<"the majority element is :"<<result<<endl;
    return 0;
}