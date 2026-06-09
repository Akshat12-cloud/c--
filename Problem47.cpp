//remove occurances.
#include<iostream>
#include<string>
using namespace std;
string removeoccurance(string s,string part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}
int main(){
    string s="abdcabcbdabcababcabd";
    string part="abc";
    cout<<"the new string after removal of the invalid string patrt is :"<<removeoccurance(s,part);
    return 0;

}