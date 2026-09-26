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
Node* reversekgroup(Node* &head,int k ){
    //base case...
    if(head==NULL){
        return NULL;
    }
    //reverse first k node.
    Node* curr= head;
    Node*prev=NULL;
    Node *next=NULL;
    int count=0;
    while(curr !=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next = reversekgroup(next,k);
    }
    return prev;
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
    
    
   
    Node * tail=node1;

    insertattail(tail,12);
   
    insertattail(tail,15);
    insertattail(tail,17);
    insertattail(tail,19);
    insertattail(tail,25);

    print(head);
    head=reversekgroup(head,2);
    print (head);    
    
    return 0;
}