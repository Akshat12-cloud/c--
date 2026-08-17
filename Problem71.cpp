//sum of two array
#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> &arr){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    return arr;
}
vector<int> findarraysum(vector<int> & arr1,int n,vector<int> &arr2,int m){
    int i=n-1;
    int j=m-1;
    vector<int> ans;
    int carry=0;
    while(i>=0 && j>=0){
        int val1=arr1[i];
        int val2=arr2[j];
        int sum=val1 +val2 +carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;

    }
    while(i>=0){
        int sum=arr1[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0){
        int sum=arr2[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;

    }
    while(carry !=0){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    return reverse(ans);

}
int main(){
    vector<int> arr1={9,9,1};
    vector<int> arr2={1,1,1};
    vector<int> result=findarraysum(arr1,3,arr2,3);
    cout<<"the sum of the array is :"<< endl;
    for(int i=0;i<result.size();i++){
       cout << result[i] << " ";
    } 
    
    return 0;
}