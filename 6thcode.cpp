#include<iostream>

void printnumber(int n){
    for (int i=1;i<=n;i++){
        if (i%2!=0){
            std::cout<<i<<" ";
        }
        else{
            continue;

         }     
    
    }
}

    int main(){
        int n;
        std::cout<<"enter the number ";
        std::cin>>n;
        printnumber(n);
        return 0;

    }
