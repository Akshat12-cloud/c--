//check palindrom.
#include<iostream>
using namespace std;
int getlength(char a[]){
    int count=0;
    for(int i=0;a[i]!=0;i++){
        count++;
    }
    return count;
}
bool checkpalindrom(char a[]){
    int s=0;
    int e=getlength(a)-1;
    while(s<e){
        if(a[s++]!=a[e--]){
            return 0;
        }
        else{
           s++;
           e--;
        }
    }
    return 1;
}
int main(){
    char a[10];
    cout<<"enter the word :"<<endl;
    cin>>a;
    cout<<endl;
    cout<<"palindrom or not :"<<checkpalindrom(a)<<endl;
    return 0;
}