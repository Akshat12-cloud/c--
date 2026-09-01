#include<iostream>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;

    void print(){
        cout<<"level is :"<<level<<endl;
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
    //static allocation
    hero ramesh;
    ramesh.sethealth(70);
    ramesh.setlevel('A');
    cout<<"health is :"<<ramesh.gethealth()<<endl;
    cout<<"level is :"<<ramesh.getlevel()<<endl;
  
    //Dynamically allocation
    hero *b=new hero;
    b->sethealth(80);
    b->setlevel('C');
    //method 1
    cout<<"health is :"<<(*b).gethealth()<<endl;
    cout<<"level is :"<<(*b).getlevel()<<endl;
    //method 2
    cout<<"health is :"<<b->gethealth()<<endl;
    cout<<"level is :"<<b->getlevel()<<endl;
    return 0;



}