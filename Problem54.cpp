/* Given an integer array nums, move all the 0s to the end of the array
 while maintaining the relative order of the non-zero elements.
*/
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}