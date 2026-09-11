#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        if(next !=NULL){
            delete next;
            next=NULL;
        }
    }

};
void print(Node* &head){
    Node*temp=head;
    while(temp !=NULL){
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    cout<<endl;

}
int getlength(Node* &head){
    Node* temp=head;
    int cnt =0;
    while(temp !=NULL){
        cnt++;
        temp=temp->next;
    } 
    return cnt;

}
void insertathead(Node* &head,int data){
    Node*temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertattail(Node*&tail,int data){
    Node*temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertatposition(Node* &head,Node* &tail,int position,int data){
    if(position==1){
        insertathead(head,data);
        return ;
    }
    int cnt=1;
    Node*temp=head;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(head,data);
        return;
    }
    Node*nodetoinsert=new Node(data);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;


}
void deletenode(Node* &head ,int position){
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //delete last node and any node.
        Node*curr=head;
        Node*previous=NULL;
        int cnt=1;
        while(cnt<position){
            previous=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        previous->next=curr->next;
        curr->next=NULL;
        delete curr;


    }

}
int main(){
    Node* node1=new Node(10);
    Node *head=node1;
    Node*tail=node1;
    print(head);
    insertathead(head,5);
    print(head);
    insertathead(head,2);
    print(head);
    insertattail(tail,15);
    print(head);
    insertatposition(head,tail,3,12);
    print(head);
    deletenode(head,2);
    print (head);

    int len=getlength(head);
    cout<<len<<endl;
    return 0;
}