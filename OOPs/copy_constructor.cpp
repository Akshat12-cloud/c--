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

};
int main(){
    hero suresh;
    suresh.sethealth(70);
    suresh.setlevel('A');
    suresh.print();
    hero ramesh(suresh);
    ramesh.print();

    
    return 0;

}
