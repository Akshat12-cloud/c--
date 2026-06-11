//get max occurance.
#include <iostream>
#include <string>
using namespace std;

char getMaxOccChar(string s) {
    int count[26] = {0};

    // Count frequency
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        count[index]++;
    }

    // Find maximum frequency
    int maxi = -1;
    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] > maxi) {
            maxi = count[i];
            ans = i;
        }
    }

    return 'a' + ans;
}

int main() {
    string s = "testsample";
    cout << "Maximum occurring character: "
         << getMaxOccChar(s) << endl;
    return 0;
}