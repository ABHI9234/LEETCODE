class Solution {
public:
string bs(int x, int n) {
        string ans;
        while(x) {
            if(x & 1) ans.push_back('1');
            else ans.push_back('0');
            x >>= 1;
        }
        while(ans.size() != n) ans.push_back('0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        for(int i = 0; i < (1<<n); i++) {
            string s = bs(i, n);
            int cost = 0; bool skip = false;
            for(int j = 0; j < n; j++) {
                if(j && s[j] == '1' && s[j-1] == '1') {skip = true; break;}
                if(s[j] == '1') cost+=j;
            }
            if(skip || cost > k) continue;
            ans.push_back(s);
        }
        return ans;
    }
};