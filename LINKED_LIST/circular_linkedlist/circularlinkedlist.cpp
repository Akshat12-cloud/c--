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
        return;
    }
    Node*curr=tail;
    while(curr->data !=element){
        curr=curr->next;
    }
    Node*newnode=new Node(data);
    newnode->next=curr->next;
    curr->next=newnode;
}
void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"the node is empty"<<endl;
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp=temp->next; 

    }while( temp !=tail);
    cout<<endl;   
}
void deletenode(Node * &tail,int value){
    if(tail==NULL){
        cout<<"the node is empty already"<<endl;
        return;

    }
    else{
        Node* prev=tail;
        Node* curr=tail->next;
        while(curr->data != value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1-node rahega agr to...
        if(curr==prev){
            tail=NULL;
        }
        //2-node wale ke liye...
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
    
}



int main(){
   
    Node *tail=NULL;
    insertnode(tail,5,20);
    insertnode(tail,20,30);
    insertnode(tail,30,40);
    insertnode(tail,40,50);
    print(tail);
    deletenode(tail,20);
    print(tail);
    
    return 0;

}