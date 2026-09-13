//Reverse a linked list.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node* &head){
    Node*temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertattail(Node* &tail,int data){
    Node*temp=new Node(data);
    tail->next=temp;
    tail=tail->next;
}
void reverse(Node * &head){
    Node* forward=NULL;
    Node* curr=head;
    Node* prev=NULL;
    while(curr !=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    print(prev);
}

int main(){
    Node*node1=new Node(10);
    Node*head=node1;
    Node * tail=node1;
    
    insertattail(tail,20);
    insertattail(tail,30);
    insertattail(tail,40);
    insertattail(tail,50);
    insertattail(tail,60);
    print(head);
    reverse(head);
    
    return 0;

}