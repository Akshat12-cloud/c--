 
#include<iostream>
using namespace std;
void intersection(int A1[],int A2[],int size1,int size2){
for(int i=0;i<size1;i++){
    for(int j=0;j<size2;j++){
        if (A1[i]==A2[j]){
            cout<<A1[i]<<" ";
            break;

        }
    }
}}
int main(){
    int A1[]={1,2,4,6,7,4,10,11};
    int A2[]={2,3,4,5,6,7,8,9};
    int size1=sizeof(A1)/sizeof(A1[0]);
    int size2=sizeof(A2)/sizeof(A2[0]);
    
    intersection(A1,A2,size1,size2);
    return 0;
}
