class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            if (a.length() == b.length()) {
                return a < b;
            }
            return a.length() > b.length();
        });
        for (const string& word : dictionary) {
            int i = 0; 
            int j = 0; 
            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    j++; 
                }
                i++; 
            }
            if (j == word.length()) {
                return word; 
            }
        }

        return "";
    }
};