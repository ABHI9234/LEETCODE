class Solution {
public:
    int paths(int m,int n,vector< vector<int>>& dp){
        int i =m;
        int j = n;
        if(i<0||j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = paths(m-1,n,dp);
        int left = paths(m,n-1,dp);
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector< vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        
        // for(int i =0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         int down = 0;
        //         int right = 0;
        //         if(i==0 && j==0) continue;
        //         if(i-1>=0)  down = dp[i-1][j];
        //         if(j-1>=0) right = dp[i][j-1];
        //         dp[i][j] = down + right;
        //     }
            
        // }
        return paths(m-1,n-1,dp);
        // return dp[m-1][n-1];
    }
};