//#QUEUE---->
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("love");
    q.push("babbar");
    q.push("kumar");
    cout<<"first element :"<<q.front()<<endl;
    cout<<"last element :"<<q.back()<<endl;
    q.pop();
    cout<<"first element :"<<q.front()<<endl;
    cout<<"size of the queue after pop :"<<q.size()<<endl;
    return 0;




}