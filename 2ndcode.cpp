//create a calculator

#include<iostream>

int main (){
    char op;
    double num1;
    double num2;
    double result;
    std::cout <<"enter the first number:";
    std::cin >>num1;
    std::cout<<"enter the second number:";
    std::cin >>num2;
    std::cout<<"enter t5he operator(+,-,*,/):";
    std::cin >>op;
    switch(op){
    case '+':
        result=num1+num2;
        std::cout <<result;
        break;
    case '-':
        result=num1-num2;
        std::cout<<result;
        break;
    case '*':
        result=num1*num2;
        std::cout<<result;
        break;
    case '/':
        result=num1/num2; 
         
        std::cout<<result;
        break;
    default:
        std::cout<<"invalid operator";

    }
    return 0;


}