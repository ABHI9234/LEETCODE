class Solution {
public:
    int f(int i, int buy,vector<int>& p,vector<vector<int>>& dp,int n){
        if(i == n) return 0;
        if(dp[i][buy] != -1) 
            return dp[i][buy];
        int profit; 
        if(buy == 1){
            profit = max(-p[i] + f(i+1, 0,p,dp,n),f(i+1, 1,p,dp,n));
        }
        else{
            profit = max(p[i] + f(i+1, 1,p,dp,n),f(i+1, 0,p,dp,n));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& p) {             
        int n = p.size();  
        vector<vector<int>> dp(n, vector<int>(2, -1));    
        return f(0, 1,p,dp,n);          
    }
};
