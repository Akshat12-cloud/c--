#include<iostream>
using namespace std;
class hero{
    private:
    int health=0;
    public:
    char level;

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
    hero ramesh;
    cout<<"health is :"<<ramesh.gethealth()<<endl;
    //use setter
    ramesh.sethealth(70);
    ramesh.setlevel('C');
    cout<<"health is :"<<ramesh.gethealth()<<endl;
    cout<<"level is :"<<ramesh.level<<endl;
    return 0;

}
