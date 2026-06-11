class Solution {
private:
    int solve(int i, int b, vector<vector<int>>& items, vector<int>& free_bonus, vector<vector<int>>& dp) {
        // Base Case: Out of items or budget exhausted
        if (i == 0 || b == 0) return 0;
        
        if (dp[i][b] != -1) return dp[i][b];
        
        int price = items[i - 1][1];
        
        // Choice 1: Completely skip this item type
        int ans = solve(i - 1, b, items, free_bonus, dp);
        
        // Choice 2: Buy at least 1 copy (if budget allows)
        if (b >= price) {
            // Option 2A: Buy EXACTLY 1 copy. 
            // Yields: 1 + its free_bonus copies. Then we move to the next item type (i - 1).
            int buy_one = 1 + free_bonus[i - 1] + solve(i - 1, b - price, items, free_bonus, dp);
            
            // Option 2B: Buy MULTIPLE copies. 
            // Yields: 1 copy. Crucially, we stay on the SAME item index 'i' to allow unbounded purchases.
            int buy_more = 1 + solve(i, b - price, items, free_bonus, dp);
            
            ans = max({ans, buy_one, buy_more});
        }
        
        return dp[i][b] = ans;
    }

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free_bonus(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free_bonus[i]++;
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, -1));
        return solve(n, budget, items, free_bonus, dp);
    }
};