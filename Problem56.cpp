// shifting element right by one position.
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    k = k % n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    rotate(nums, 3);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}