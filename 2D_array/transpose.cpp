#include<iostream>
using namespace std;

void transpose(int arr[][4], int row, int col) {
    int m = col;
    int n = row;

    int ans[m][n];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ans[j][i] = arr[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[2][4] = {
        {2,3,4,5},
        {6,7,8,9}
    };

    transpose(arr, 2, 4);

    return 0;
}