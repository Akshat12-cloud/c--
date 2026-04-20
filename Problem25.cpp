//book allocation problem.(minimum number of pages allocate )
#include<iostream>
using namespace std;
bool ispossible(int arr[],int size,int m,int mid){
    int studentcount=1;
    int pagesum=0;
    for (int i=0;i<size;i++){
        if (arr[i]+pagesum<=mid){
            pagesum+=arr[i];
        }
        else{
            studentcount+=1;
            if(studentcount>m || arr[i]>mid ){
                return false;
            }
            pagesum=0;
            pagesum+=arr[i];
        }
    }
    return true;
}
int allocatebook(int arr[],int size,int m){
    int s=0;
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while (s<=e){
        if (ispossible(arr,size,m,mid)){
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
    int arr[]={10,20,30,40};
    int size=sizeof(arr)/sizeof(arr[0]);
    int answer=allocatebook(arr,size,2);
    if (answer!=-1){
        cout<<"the answer is :"<<answer<<endl;
    }
    else{
        cout <<"alloaction not possible";
    }
    return 0;
}