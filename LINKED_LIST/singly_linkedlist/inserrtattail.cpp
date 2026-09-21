#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertathead(Node * &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;

}
void insertattail(Node * &tail,int data){
    Node *temp=new Node(data);
    tail->next=temp;
    tail=tail->next;
}

void print(Node* &head){
    Node * temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    //create a node
    Node *node1=new Node(10);


    //head piointed to node1
    Node * head= node1;
    print(head);
    insertathead(head,12);
    print(head);
    Node * tail=node1;
    print(head);
    insertattail(tail,12);
    print(head);
    insertattail(tail,15);
    print(head);
    
    
    return 0;
}