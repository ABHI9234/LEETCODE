class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        // Find the upper limit for possible XOR values (next power of 2)
        int limit = 1;
        while (limit <= max_val) {
            limit *= 2;
        }
        
        // If the target requires bits that don't exist in any array element, it's impossible.
        if (target >= limit) return -1;
        
        int n = nums.size();
        
        // dp[i][j] initialized to a very small number representing 'impossible'
        vector<vector<int>> dp(n + 1, vector<int>(limit, -1e9));
        
        // Base case
        dp[0][0] = 0; 
        
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = 0; j < limit; j++) {
                
                // 1. Not Pick
                int not_pick = dp[i - 1][j];
                
                // 2. Pick
                // We check dp[i-1][j ^ x] to ensure we build off a valid previous state
                int pick = dp[i - 1][j ^ x] + 1;
                
                dp[i][j] = max(not_pick, pick);
            }
        }
        
        // If the target state is still negative, it's impossible to reach
        if (dp[n][target] < 0) return -1;
        
        // Minimum removals = Total elements - Maximum elements we could keep
        return n - dp[n][target];
    }
};