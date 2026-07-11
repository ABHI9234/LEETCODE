class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        string best = "";
        string prefix = "";
        for (int i = 0; i < s.size(); i++) {
            for (int c = (target[i] - 'a') + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string candidate = prefix;
                    candidate += (char)(c + 'a');
                    vector<int> temp_freq = freq;
                    temp_freq[c]--;
                    for (int k = 0; k < 26; k++) {
                        candidate.append(temp_freq[k], (char)(k + 'a'));
                    }
                    best = candidate; 
                    break; 
                }
            }
            if (freq[target[i] - 'a'] > 0) {
                prefix += target[i];
                freq[target[i] - 'a']--;
            } else {
                break;
            }
        }        
        return best;
    }
};