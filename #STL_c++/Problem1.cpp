//#ARRAY--->
#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,4> a ={1,3,5,7};
    int size=a.size();
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";

    }
    cout<<"element at 3rd index is :"<<a.at(3)<<endl;
    cout<<"empty or not :"<<a.empty()<<endl;
    cout<<"first element :"<<a.front()<<endl;
    cout<<"last element :"<<a.back()<<endl;
    return 0;
}