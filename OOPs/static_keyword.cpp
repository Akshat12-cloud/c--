#include<iostream>
using namespace std;
class hero{
    private:
    int health=0;
    public:
    char level;
    static int time;

    hero(){
        cout<<"default constructor called"<<endl;
    }


    void print(){
        cout<<"level :"<<this->level<<endl;
        cout<<"health :"<<this->health<<endl;
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
int hero::time=5;
int main(){
    cout<<hero::time<<endl;   

    
    return 0;

}
