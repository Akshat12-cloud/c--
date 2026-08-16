//Book allocation problem.
#include<iostream>
using namespace std;
bool ispossible(int arr[],int size,int k,int mid){
    int student=1;
    int pagesum=0;
    for(int i=0;i<size;i++){
        if(pagesum+arr[i]<=mid){
            pagesum+=arr[i];
        }
        else{
            student++;
            if(student>k || arr[i]>mid){
                return false;
            }
            pagesum=0;
            pagesum=pagesum+arr[i];

        }
    }
    return true;

}
int bookallocate(int arr[],int size,int k){
    int s=0;
    int sum=0;
    int ans=-1;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int e=sum;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ispossible( arr, size,k,mid)){
            ans=mid;
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
    int arr[]={10,20,30,40,50};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    int result=bookallocate(arr,size,k);
    if(result !=-1){
        cout<<"the answer is :"<<result<<endl;
    }
    else{
        cout<<"not possible"<<endl;
    }
    return 0;

}