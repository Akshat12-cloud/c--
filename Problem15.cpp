//find unique element.
#include<iostream>
int findUnique(int arr[],int size){

    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i]; 
    }
    return ans;
}
int main (){
    int arr[15]={1,1,2,3,4,4,3,2,5,7,8,7,9,8,9};
    std::cout<<findUnique(arr,15)<<std::endl;
    return 0;
}