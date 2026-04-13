//Print numbers from n down to 1 using recursion.
#include<iostream>

void printnumbers(int n){
    for (int i=1;i<=n;i--)
    {
        std::cout<<i<<" ";

    }
}
int main(){
    int n;
    std::cout<<"enter the number n:";
    std::cin>>n;
    printnumbers(n);

    return 0;
}


