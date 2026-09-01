#include<iostream>
#include<string>
using namespace std;
bool checkanagram(string s,string t){
    int n=s.length();
    string test="";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i]==t[j]){
                test.push_back(s[i]);
                t.erase(j,1);
                break;
            }
        }
        
    }
    if(s==test){
        return true;
    }
    else{
        return false;
    } 

}
int main(){
    string s="dog";
    string t="god";
    bool check=checkanagram(s,t);
    cout<< check<<endl;
    return 0;
}
