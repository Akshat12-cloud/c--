//#MAP---->
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> m;
    m[1]="babbar";
    m[13]="love";
    m[2]="kumar";
    for(auto i:m){
        cout<<i.first<<endl;

    }
    m.insert({5,"ashique"});
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;

    }//before erase.
    cout<<"finding---> 13 :"<<m.count(13);
    m.erase(13);
    cout<<"after erase :"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;

    }
    auto it=m.find(5);
    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;

    }
    return 0;
}