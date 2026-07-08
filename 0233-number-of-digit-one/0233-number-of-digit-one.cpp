class Solution {
public:
    int solve(string& s,int idx, int tight, int cnt,vector<vector<vector<int>>>& dp) {
        if (idx == s.size()) {
            return cnt;
        }
        if (dp[idx][tight][cnt] != -1) {
            return dp[idx][tight][cnt];
        }
        int limit = tight ? (s[idx] - '0') : 9;
        int ans = 0;
        for (int i = 0; i <= limit; i++) {
            int nextCnt = cnt + (i == 1 ? 1 : 0);
            int nextTight = tight && (i == limit);
            ans += solve(s,idx + 1, nextTight, nextCnt,dp);
        }
        return dp[idx][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        string s = to_string(n);
        int len = s.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(len + 1, -1)));
        return solve(s,0, 1, 0,dp);
    }
};