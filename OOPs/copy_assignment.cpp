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
    ~hero(){
        cout<<"destructor called"<<endl;
    }

};
int main(){
    //static
    hero suresh;
    //dynamic
    hero *ramesh=new hero;
    delete ramesh;


    
    return 0;

}
