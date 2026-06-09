//check palindrom.
#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool valid(char ch){
    if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
    {
    return 1;
    }
    return 0;
}
char tolowercase(char ch){
    if((ch>='a' && ch<='z')||(ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char temp=ch-'A' + 'a';
        return temp;
    }
}
bool ispalindrom(string a){
    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a[s] != a[e])
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

    
bool checkpalindrom(string s){
    //valid character ko temp me dal denge.
    string temp="";
    for(int i=0;i<s.length();i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }
    //sabko lowercase me kr denge.
    for(int j=0;j<temp.length();j++){
        temp[j]=tolowercase(temp[j]);
    }
    //now we check palindrom or not.
    return ispalindrom(temp);
}

int main()
{
    string s="nb123T321bn";
    cout<<"it is palindrom or not :"<< checkpalindrom(s);
}
