//reverse a string.
#include<iostream>
#include<vector>
using namespace std;
int getlength(char a[]){
    int count=0;
    for(int i=0;a[i]!=0;i++){
        count++;
    }
    return count;
}
void reverse(char a[]){
    int n=getlength(a);
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(a[s++],a[e--]);
    }

}
void print(char a[]){
    for(int i=0;i<getlength(a);i++){
        cout<< a[i];
    }
    
}
int main(){
    char a[20]="akshat";
    reverse(a);
    print(a);
    return 0;

}