//binary search.
#include<iostream>
using namespace std;
int binarysearch(int num[],int size,int key){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while (s<=e){
        if (key==num[mid]){
            return mid;
        }
        else if(key<num[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main(){
    int num[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(num)/sizeof(num[0]);
    int key;
    cout<<"enter the element to search:"<<endl;
    cin>>key;
    int result=binarysearch(num,size,key);
    cout<<"the index of the element is :"<<result;
    return 0;

}