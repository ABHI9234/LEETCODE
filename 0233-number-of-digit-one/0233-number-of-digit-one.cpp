class Solution {
public:
    int solve(string &s, int i,int tight,int cnt,vector<vector<vector<int>>>& dp){
        if(i==s.length()) return cnt;
        if(dp[i][tight][cnt]!=-1) return dp[i][tight][cnt];
        
        int limit = tight?(s[i]-'0'):9;
        int ans = 0;
        for(int j =0;j<=limit;j++){
            int ncnt = cnt+ (j==1 ? 1:0);
            int ntight = tight && (j==limit);
            ans+=solve(s,i+1,ntight,ncnt,dp);
        }
        return dp[i][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        int len = s.size();
        vector<vector<vector<int>>> dp(len,vector<vector<int>>(2,vector<int>(len+1,-1)));
        return solve(s,0,1,0,dp);
    }
};