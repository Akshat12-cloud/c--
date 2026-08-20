#include<iostream>
#include<vector>
using namespace std;
vector<int> luckyno(vector<vector<int>> arr){
    int row=arr.size();
    int col=arr[0].size();
    vector<int> arr1;
    
    int min;
    int i=0;
    for(int j=0;j<col-1;j++){
        if(arr[i][j]<min){
            min=arr[i][j];
        }
        arr1.push_back(min);
        
        if(i<row-1){
            i++;
        }
        
    }
    return arr1;

}
int main(){
    vector<vector<int>> arr={{10,11,12},{9,7,3},{15,18,20}};

    vector<int> result=luckyno(arr);
    for(int i=0;i<result.size();i++){

    cout<<result[i]<<endl;
}
    return 0;

}