//introduction...basic.
#include<iostream>
using namespace std;
int main(){
    int num=5;
    int arr[10]={2,6,7};
    cout<<"address of the num is :"<<&num<<endl;

    int *ptr=&num;
    cout<<"the value of num is="<<*ptr<<endl;
    cout<<"1st "<<arr<<endl;
    cout<<"2nd"<<&arr[0]<<endl;
    cout<<"3rd"<<*arr<<endl;
    cout<<"4th"<<*arr+1<<endl;    
    cout<<"5th"<<*(arr+1)<<endl;
    int temp[10];
    cout<< sizeof(temp)<<endl;
    int *pt=&temp[0];
    cout<< sizeof(pt)<<endl;
    cout<< sizeof(*pt)<<endl;
    return 0;

}