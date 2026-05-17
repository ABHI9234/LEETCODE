class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128,0);
        int i =0;
        int j =0;
        int n = s.size();
        int maxlen = 0;
        while(j<n){
            v[s[j]]++;
            while(v[s[j]]>1){
                v[s[i]]--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};