#include<iostream>
using namespace std;
class hero{
    public:
    int health;
    char level;
};
int main(){
    //cretion of object.
    hero ramesh;
    ramesh.health=70;
    ramesh.level='C';
    cout<<"health :" << ramesh.health<<endl;
    cout<<"level :"<<ramesh.level<<endl;
    return 0;

}