#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        if(next !=NULL){
            delete next;
            next=NULL;
        }
    }

};
void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}
void insertattail(Node* &tail,int data){
    Node*temp=new Node(data);
    tail->next= temp;
    tail=temp;
}
void deletenode(Node* &head,int position){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*prev=NULL;
        Node*curr=head;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertattail(tail,20);
    print(head);
    insertattail(tail,30);
    insertattail(tail,40);
    insertattail(tail,50);
    print(head);
    deletenode(head,4);
    print(head);
    return 0;



}