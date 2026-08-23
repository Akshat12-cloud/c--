/*given an string  of unique element ,return all possible subsequence .
the solution set must not contain duplicate subsequence.return the solution in any order.
example1--->"abc"
o/p---->a b c ab ac bc abc*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve(string str,string output,int i,vector<string> &ans){
    //base case.
    if(i>=str.length()){
        if(output.length()>=1){
            ans.push_back(output);
        }
        return;
    }
    //exclude.
    solve(str,output,i+1,ans);
    //include.
    char element=str[i];
    output.push_back(element);
    solve(str,output,i+1,ans);
}
vector<string> subsequence(string str){
    vector<string> ans;
    string output="";
    int index =0;
    solve(str,output,index,ans);
    return ans;
}  
int main(){
    string str="abc";
    vector<string> ans= subsequence(str);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
