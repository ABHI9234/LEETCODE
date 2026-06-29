class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        if (s.size() < t.size() || s.empty() || t.empty()) return "";
        int n = s.size();
        int m = t.size();
        for(int i =0;i<m;i++){
            mp[t[i]]++;
        }
        unordered_map<char,int> mp2;
        int i =0;
        int j = 0;
        int minl = INT_MAX;
        int startIdx = 0;
        int required = t.size();
        while(j<n){
            if (mp[s[j]] > 0) {
                required--;
            }
            mp[s[j]]--;
            while (required == 0) {
                if (j - i + 1 < minl) {
                    minl = j - i + 1;
                    startIdx = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    required++;
                }
                i++; 
            }
            j++;
        }
        return minl == INT_MAX ? "" : s.substr(startIdx, minl);
    }
};