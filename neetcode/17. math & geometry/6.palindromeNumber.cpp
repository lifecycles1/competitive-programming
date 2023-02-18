// Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        long long y = 0;
        long long z = x;
        while (z > 0) {
            y = y * 10 + z % 10;
            z /= 10;
        }
        return x == y;
    }
};