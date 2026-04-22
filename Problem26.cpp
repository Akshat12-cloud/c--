//find k element between pivo element and arr[n-1] element.
#include<iostream>
#include<vector>
using namespace std;
int findpivot(vector<int>& arr,int size){
    int s=0;
    int e=size-1;
    int mid= s+(e-s)/2;
    while (s<e){
        if (arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int binarysearch(vector<int>& arr,int s,int e ,int target){
    int start=s;
    int end=e;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(target==arr[mid]){
            return mid;
        }
        else if(target>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return start;

}
int findelement(vector<int>& arr,int size,int target){
    int pivot=findpivot(arr,size);
    if(arr[pivot]<=target && target<=arr[size-1]){
        return binarysearch(arr,pivot,size-1,target);
    }
    else{
        return binarysearch(arr,0,pivot-1,target);
    }
}
int main(){
    vector<int> arr ={7,9,13,1,2,4};
    int size=arr.size();
    int index=findelement(arr,size,2);
    cout<<"the position of the key element is :" << index <<endl;
}