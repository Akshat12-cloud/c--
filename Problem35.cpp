// Q.find first and last occurance of an elememnt in a array.
#include<iostream>
using namespace std ;
int firstoccurance(int arr[],int size,int key)
{
int start=0;
int end=size-1;
int mid=start+((end-start)/2);
int ans=-1;
while(start<=end){
    if(key==arr[mid]){
        ans=mid;
        end=mid-1;
    }
    else if(key>arr[mid]){
        start=mid+1;
    }
    else if(key<arr[mid]){
        end=mid-1;
    }
    mid=start +((end-start)/2);

}
return ans;
}
int lastoccurance(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start +((end-start)/2);
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
        mid=start +((end-start)/2);

    }
    return ans;
}
int main(){
    int arr[]={2,3,4,4,5,5,5,5,6,7,8,8,8,9,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int first=firstoccurance(arr,size,5);
    int last=lastoccurance(arr,size,5);
    cout<<"the first occurance of the 5 is :"<<first<<endl;
    cout<<"the last occurance of the 5 is :"<<last<<endl;
    return 0;

}
