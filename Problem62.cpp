//spiral print.
#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralprint(vector<vector<int>> &arr){
    vector<int> ans;
    int row=arr.size();
    int col=arr[0].size();
    int count =0;
    int total=row*col;
    int startingrow=0;
    int startingcol=0;
    int endingrow=row-1;
    int endingcol=col-1;
    while(count<total){
        //print starting row.
        for(int i=startingcol;count<total && i<=endingcol;i++){
            ans.push_back(arr[startingrow][i]);
            count++;

        }
        startingrow++;
        //print ending column.
        for(int i=startingrow;count<total && i<=endingrow;i++){
            ans.push_back(arr[i][endingcol]);
            count++;

        }
        endingcol--;
        //print ending row.
        for(int i=endingcol;count<total && i>=startingcol;i--){
            ans.push_back(arr[endingrow][i]);
            count++;
        }
        endingrow--;
        //printstarting column.
        for(int i=endingrow;count<total && i>=startingrow;i--){
            ans.push_back(arr[i][startingcol]);
            count++;

        }
        startingcol++;


    }
    return ans;


}

int main(){
    vector<vector<int>> arr={{1},{2},{3}};
    vector<int> result=spiralprint(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}