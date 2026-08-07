class Solution {
public:
    int f(string& s,string& v, vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==v[j]) return dp[i][j] = 1+f(s,v,dp,i-1,j-1);
        else return dp[i][j] = max(f(s,v,dp,i-1,j),f(s,v,dp,i,j-1));
    }
    int minInsertions(string s) {
        string v = s;
        reverse(v.begin(),v.end());
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return n-f(s,v,dp,n-1,n-1);
    }
};