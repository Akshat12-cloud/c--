//find the first and last occurance of an element in array.
#include<iostream>

using namespace std;
int indexfirst(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans=-1;
    while (start<=end){
        if (key==arr[mid]){
            ans=mid;
            end=mid-1;

        }
        else if(key<arr[mid]){
            end=mid-1;

        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        mid=start + ((end-start)/2);

    }
    return ans;

}
int indexlast(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans=-1;
    while (start<=end){
        if (key==arr[mid]){
            ans=mid;
            start=mid+1;

        }
        else if(key<arr[mid]){
            end=mid-1;

        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        mid=start + ((end-start)/2);

    }
    return ans;

}


int main(){
    int arr[]={1,2,3,4,5,5,5,6,6,7,8,8,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
    cout<<"entr the key element"<<endl;
    cin>>key;

    int indexes=indexfirst(arr,size,key);
    cout<<"the first  index of the "<<key<<"is :"<<indexes<<endl;
    int lastoccur= indexlast(arr,size,key);
    cout<<"the last  index of the "<<key<<"is :"<<lastoccur<<endl;


}