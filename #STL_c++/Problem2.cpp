//#VECTOR---->
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"capacity-->"<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"capacity-->"<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"capacity-->"<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"capacity-->"<<v.capacity()<<endl;
    cout<<"size-->"<<v.size()<<endl;
    cout <<"eleent at index 2nd is :"<<v.at(2)<<endl;
    cout <<"front element is :"<<v.front()<<endl;
    cout <<"back element is :"<<v.back()<<endl;
    cout <<"before pop :"<<endl;
    for (auto i: v){
        cout <<i<<" ";

    }cout<<endl;
    v.pop_back();
    cout<<"after pop :"<< endl;
    for (auto i:v){
        cout<< i << " ";

    }cout<<endl;
    cout <<"before clear size :"<<v.size();
    v.clear();
     cout <<"after  clear size :"<<v.size()<<endl;
     




}