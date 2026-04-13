#include <iostream>

void sum(int n){
    int sum=0;
    
    int digit=0;
    while (n>0){
        digit=n%10;
        sum=digit+sum;
        n=n/10;
    }
    std::cout<<"the sum of the digits is:"<<sum;

}
int main (){
    int n ;
    std::cout<<"enter the number n";
    std::cin>>n;
    sum(n);
    return 0;
}
