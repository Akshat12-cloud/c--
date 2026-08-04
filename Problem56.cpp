// shifting element right by one position.
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    while (k--) {
        int last = nums[n - 1];

        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }

        nums[0] = last;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    rotate(nums, 2);

    for (int num : nums) {
        cout << num << " ";
    }
}