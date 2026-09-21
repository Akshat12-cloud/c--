#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        if(this->next !=NULL){
            delete next;
            next=NULL;
            
        }
    }
};
void insertnode(Node* &tail,int element,int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }
    Node*curr=tail;
    while(curr->data !=element){
        curr=curr->next;
    }
    Node*newnode=new Node(data);
    newnode->next=curr->next;
    curr->next=newnode;
}
print(Node*&tail){
    
}



int main(){
   
    Node *tail=NULL;
    insertnode(tail,5,20);
    print(head);
    
    return 0;

}