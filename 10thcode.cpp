//Reverse a number recursively.
#include <iostream>

int reverseNumber(int n, int rev = 0) {
    if (n == 0)
        return rev;

    return reverseNumber(n / 10, rev * 10 + n % 10);
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int result = reverseNumber(n);
    std::cout << "Reversed number: " << result;

    return 0;
}