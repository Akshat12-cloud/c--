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
    hero(int health){
        cout<<"this->"<<this<<endl;
        this->health=health;
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
    
    
    //object creation
    hero ramesh(10);

    cout<<"address of ramesh:"<< &ramesh<<endl;
    
    //dynamically
    hero *h=new hero;

    
    return 0;

}
