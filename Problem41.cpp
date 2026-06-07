//sum of to arrays.
#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> &ans){
    int s=0;
    int e=ans.size()-1;
    while(s<=e){
        swap(ans[s++],ans[e--]);

    }cout<<endl;
    return ans;

}
vector<int> findarraysum(vector<int> &a,int n,vector<int> &b,int m){
    int i=n-1;
    int j=m-1;
    vector<int> ans;
    int carry=0;
    while(i>=0 && j>=0){
        int val1=a[i];
        int val2=b[j];
        int sum=val1 +val2 + carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    //first case
    while(i>=0){
        int sum=a[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    //second case.
    while(j>=0){
        int sum=b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }
    //third case()
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    return reverse(ans);
}

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={5,6,7};
   
    vector<int> result=findarraysum(arr1,5,arr2,3);
    for(int i:result){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}