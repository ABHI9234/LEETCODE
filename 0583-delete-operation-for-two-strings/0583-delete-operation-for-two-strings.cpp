class Solution {
public:
    int f(string& s,string& v,vector<vector<int>>& dp,int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==v[j]) return dp[i][j] = 1+f(s,v,dp,i-1,j-1);
        else return dp[i][j] = max(f(s,v,dp,i-1,j),f(s,v,dp,i,j-1));
    }
    int minDistance(string s, string v) {
        int n = s.size();
        int m = v.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return (m+n-2*f(s,v,dp,n-1,m-1));

    }
};