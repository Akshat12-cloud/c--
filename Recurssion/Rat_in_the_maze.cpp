/* You are given an N × N maze represented by a binary matrix. Each cell contains either:
1 → The cell is open and the rat can move through it.
0 → The cell is blocked and the rat cannot enter it.
The rat starts at the top-left cell (0,0) and must reach the bottom-right cell (N-1,N-1).
The rat can move in four directions:
Down (D)
Left (L)
Right (R)
Up (U)
Find and print all possible paths from the starting cell to the destination.
If no path exists, return an empty list.
Example:
Input:
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
Output:
DDRDRR
DRDDRR
This is a classic backtracking + recursion problem.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool ispossible(vector<vector<int>> arr,int n,int x,int y,vector<vector<int>> visited){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (arr[x][y]==1)){
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &arr,int n,int x,int y,string path,vector<string> &ans,vector<vector<int>> visited){
    //base case.
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return ;
    }
    //starting point source.
    visited[x][y]=1;
    //4 choices ----->D,L,R,U
    //DOWN
    int newx=x+1;
    int newy=y;
    if(ispossible(arr,n,newx,newy,visited)){
        path.push_back('D');
        solve(arr,n,newx,newy,path,ans,visited);
        path.pop_back();
    }
    //right
    newx=x;
    newy=y+1;
    if(ispossible(arr,n,newx,newy,visited)){
        path.push_back('R');
        solve(arr,n,newx,newy,path,ans,visited);
        path.pop_back();
    }
    //LEFT
    newx=x;
    newy=y-1;
    if(ispossible(arr,n,newx,newy,visited)){
        path.push_back('L');
        solve(arr,n,newx,newy,path,ans,visited);
        path.pop_back();
    }
    //UP
    newx=x-1;
    newy=y;
    if(ispossible(arr,n,newx,newy,visited)){
        path.push_back('U');
        solve(arr,n,newx,newy,path,ans,visited);
        path.pop_back();
    }
    visited[x][y]=0;

}
vector<string> findpath(vector<vector<int>> arr,int n){
    vector<string> ans;
    int srcx=0;
    int srcy=0;
    vector<vector<int>> visited = arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    string path="";
    solve(arr,n,srcx,srcy,path,ans,visited);
    sort(ans.begin(),ans.end());
    return ans;

}
int main(){
    vector<vector<int>> arr={{1,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n=arr.size();
    vector<string> path=findpath(arr,n);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    return 0;
}