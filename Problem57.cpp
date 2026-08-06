// rotate 3 place to an array.
#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> temp();
  
    
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=arr[i];
    }
    arr=temp;

}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11};
    int k;
    cout<<"enter rotate times"<<endl;
    cin>>k;
    rotate(arr,k);
   

}
