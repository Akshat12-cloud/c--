//find length of the string.
#include<iostream>
using namespace std;
int getlength(char name[]){
    int count=0;
    for(int i=0;name[i]!=0;i++){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cout<<"enter the name:"<<endl;
    cin>>name;
    cout<<"your name is :"<<name<<endl;
    cout<<"length :"<<getlength(name);
    return 0;

}
