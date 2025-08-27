#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        // Helper function to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd length palindrome
            expand(i, i + 1); // Even length palindrome
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    string s = "babad";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
