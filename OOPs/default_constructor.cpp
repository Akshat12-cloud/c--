/*
hero ramesh;
it create object,that call the constructor
constructor?
->object creation invoke.
->no return type.
->no parameter.
when we create object(hero ramesh;)->it call default constructor(ramesh.hero()-->def. constructor)
*/
#include<iostream>
using namespace std;
class hero{
    private:
    int health=0;
    public:
    char level;

    hero(){
        cout<<"default constructor called"<<endl;
    }

    void print(){
        cout<<level<<endl;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(char ch){
        level=ch;
    }

};
int main(){
    //this is statically.
    cout<<"hi"<<endl;
    //object creation
    hero ramesh;

    cout<<"hello"<<endl;
    //dynamically
    hero *h=new hero;

    
    return 0;

}
