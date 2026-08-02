/*Given an integer array nums, return true if any value appears at least
 twice in the array, and return false if every element is distinct.*/
 #include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i]) != s.end()) {
            return true;
        }

        s.insert(nums[i]);
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}