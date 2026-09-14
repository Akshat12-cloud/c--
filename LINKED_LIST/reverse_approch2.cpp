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
void reverse(Node*&head,Node* &curr,Node*&prev){
    //base case.
    if(curr ==NULL){
        head=prev;
        return;
    }
    Node*forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
Node* reverselinkedlist(Node * &head){
    Node* prev =NULL;
    Node*curr=head;
    reverse(head,curr,prev);
    return head;
    
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
    reverselinkedlist(head);
    
    return 0;

}