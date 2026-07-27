class Solution {
public:
    int f(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        int n = prices.size();
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy==1) profit = max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        else profit = max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};