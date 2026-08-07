//give the number of prime number that are strictly less than n.
#include<iostream>
#include<vector>
using namespace std;
int countprime(int n){
    int count =0;
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            for(int j=2*i;j<n;j=j+i){
                prime[j]=0;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cout<<"enter the number :" << endl;
    cin>>n;
    int result = countprime(n);
    cout<<"the number of prime number strictly less than n ="<<result;
    return 0;
}
