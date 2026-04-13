//Count the number of digits in a number recursively.
#include<iostream>
int countdigits(int n){
    if(n==0){
        return 0;
    }
    else{
        return 1+countdigits(n/10);
    }
    }
    int main (){
        int n;
        std::cout<<"entyere the number n:";
        std::cin>>n;
        int result=countdigits(n);
        std::cout<<"the number of digits in the number is:"<<result;
        return 0;

    }

