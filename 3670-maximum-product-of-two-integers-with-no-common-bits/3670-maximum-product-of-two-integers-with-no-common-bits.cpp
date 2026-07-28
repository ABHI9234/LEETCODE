class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        // Step 1: Find the max value to determine how many bits we need
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        int l = 0;
        while ((1 << l) <= max_val) {
            l++;
        }
        
        // Step 2: Initialize the DP array
        int limit = 1 << l;
        vector<int> dp(limit, 0);
        
        for (int x : nums) {
            dp[x] = max(dp[x], x);
        }
        
        // Step 3: SOS DP (Propagate maximums to supersets)
        for (int i = 0; i < l; i++) {
            for (int mask = 0; mask < limit; mask++) {
                if (mask & (1 << i)) {
                    dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
                }
            }
        }
        
        // Step 4: Find the maximum valid product
        long long mx = 0;
        int full_mask = limit - 1;
        
        for (int x : nums) {
            int comp = full_mask ^ x; 
            
            if (dp[comp] > 0) {
                mx = max(mx, 1LL * x * dp[comp]);
            }
        }
        
        return mx;
    }
};