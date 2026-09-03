#include<iostream>
using namespace std;
class human{
    public:
    int age;
    int weight;
    int height;
    public:
    int getage(){
        return age;
    }
    int getweight(){
        return weight;
    }
    void setweight(int w){
        int weight=w;

    }

}; 
class male:public human{
    public:
    string colour;
    void sleep(){
        cout<< " male sleep"<<endl;
    }
};
int main(){
    male m1;
    cout<<m1.age<<endl;
    cout<<m1.weight<<endl;
    cout<<m1.height<<endl;
    cout<<m1.colour<<endl;
    m1.sleep();
    return 0;
}