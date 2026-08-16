//find square root of a number.
#include<iostream>
using namespace std;
long long int binarysearch(int x){
    int s=0;
    int e=x;
    int mid=s+ (e-s)/2;
    int ans=-1;
    while(s<=e){
        long long  square=mid*mid;
        if(square==x){
            return mid;
        }
        if(square<x){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+ (e-s)/2;
    }
    return ans;
}
int squareroot(int x){
    return binarysearch(x);
}


int main(){
    
    int n;
    cin>>n;
    int result=squareroot(n);
    cout<<result<<endl;
    

    return 0;
}
