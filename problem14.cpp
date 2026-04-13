//write a code to calculate the area of the square.
#include<iostream>

void aresquare(double length){
    double area=length*length;
    std::cout<<"the area of the the square is:"<<area;

}
int main(){
    double length;
    std::cout<<"enter the length of the square:" ;
    std::cin>>length;
    aresquare(length);
    return 0;
    

}