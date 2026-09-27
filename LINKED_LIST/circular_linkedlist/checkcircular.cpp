//check circular linked list or not.
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
bool iscircular(Node* tail){
    if(tail==NULL){
        return true;
    }
    else if(tail->next==NULL){
        return false;
    }
    else{
        Node*temp=tail->next;
        while(temp !=NULL && temp !=tail){
            temp=temp->next;
        }
        if(temp==NULL){
            return false;
        }
        else{
            return true;
        }

    }


}



int main(){
   
    Node *tail=NULL;
    insertnode(tail,5,20);
    insertnode(tail,20,30);
    insertnode(tail,30,40);
    insertnode(tail,40,50);
    print(tail);
    //deletenode(tail,20);
    //rint(tail);
    bool ans=iscircular(tail);
    if(ans==true){
        cout<< "it is circular"<<endl;
    }
    else{
        cout<<"it is not circular"<<endl;

    }
    return 0;

}
