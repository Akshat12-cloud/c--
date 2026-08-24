/*given a string containing digits from 2-9 includive ,return all possible 
letter combination that the number could represent .Return in any order.
example----->i/p=digit="23"
o/p------>["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(string digit,string output,string mapping[],int index,vector<string> &ans){
    //base case.
    if(index>=digit.length()){

        ans.push_back(output);
        return;
    }
    int number=digit[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digit,output,mapping,index+1,ans);
        output.pop_back();
    }
}
vector<string> phonekeypad(string digit){
    vector<string> ans;
    string output;
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digit,output,mapping,index,ans);
    return ans;
}
int main(){
    string digit="23";
    vector<string> ans=phonekeypad(digit);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }
    return 0;
}
