#include<iostream>

int num(int n){
    if (n==1 || n==0){
        return n;
    }
    else{
        return num(n-2)+num(n-1);

    }
    }
int main (){
    int n;
    std::cout<<"enter the number for its seriesof fibonacci:";
    std::cin>>n;
    int result=num(n);
    std::cout<<result;
    return 0;

}