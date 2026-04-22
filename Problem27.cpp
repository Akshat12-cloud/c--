// find square root of a number using binary search(Time complexity = O(logn)).
#include<iostream>
using namespace std;
long long int squareroot_int(int num){
    int s=0;
    int e=num;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;

    while (s<=e){
        long long int square=mid*mid;
        if (num==square){
            return mid;
        }
        else if(num>square){
            ans=mid;
            s=mid +1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return s;

}
int main(){
    int num;
    cout<<"enter the number to find its square root :";
    cin>>num;
    int result=squareroot_int(num);
    cout<<"the square root of the number is :"<<result<<endl;
    return 0;
}