//Print numbers from 1 to n using recursion.

#include<iostream>
void printNumber(int n){
    for (int i=1;i<=n;i++){
        std::cout<<i<<" ";
    }
}
    int main (){
        int n;
        std::cout<<"enter the number n:";
        std::cin>>n;
        printNumber(n);
        return 0;

    }


    