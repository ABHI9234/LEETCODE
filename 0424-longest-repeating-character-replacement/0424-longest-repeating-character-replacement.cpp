class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0;
        int n = s.size();
        int maxFreq = 0;
        int maxlen = 0;
        for (int j = 0; j < n; j++) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};