class Solution {
private:

    int expandWithTwoPointers(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;  
            right++; 
        }
        return right - left - 1; 
    }

public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandWithTwoPointers(s, i, i);
            int len2 = expandWithTwoPointers(s, i, i + 1);
            int currentMax = max(len1, len2);
            if (currentMax > maxLen) {
                maxLen = currentMax;
                start = i - (maxLen - 1) / 2; 
            }
        }
        return s.substr(start, maxLen);
    }
};