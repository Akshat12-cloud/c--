#include<iostream>
#include<cstring>
using namespace std;
class hero{
    private:
    int health=0;
    public:
    char level;
    char *name;

    hero(){
        cout<<"default constructor called"<<endl;
        name=new char[100];
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }
    hero(hero &temp){
        this->health=temp.health;
        this->level=temp.level;
        this->name=new char[100];
        strcpy(this->name,temp.name);
    }


    void print(){
        cout<<"level :"<<this->level<<endl;
        cout<<"health :"<<this->health<<endl;
        cout<<"name :"<<this->name<<endl;
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
    hero hero1;
    hero1.sethealth(70);
    hero1.setlevel('B');
    char name[]="akshat";
    hero1.setname(name);
    hero1.print();
    hero hero2(hero1);
    hero2.print();

    
    return 0;

}
