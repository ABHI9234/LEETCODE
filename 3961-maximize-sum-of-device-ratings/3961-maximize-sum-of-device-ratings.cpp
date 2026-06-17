class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        
        long long R0 = 0;      // Sum for Strategy 1
        long long S_total = 0; // Sum of all second minimums
        
        int global_min_a = INT_MAX; 
        int min_b = INT_MAX;
        
        // Edge case: If devices only have 1 unit, moving them only creates 0s.
        if (n == 1) {
            for (int i = 0; i < m; i++) {
                R0 += units[i][0];
            }
            return R0;
        }
        
        // Iterate through each device to find its two smallest elements
        for (int i = 0; i < m; i++) {
            int a = INT_MAX; // Smallest (min1)
            int b = INT_MAX; // Second smallest (min2)
            
            for (int x : units[i]) {
                if (x < a) {
                    b = a;
                    a = x;
                } else if (x < b) {
                    b = x;
                }
            }
            
            // Accumulate values for our formulas
            R0 += a;
            S_total += b;
            global_min_a = min(global_min_a, a);
            min_b = min(min_b, b);
        }
        
        // Calculate Strategy 2
        long long R_max = S_total - min_b + global_min_a;
        
        return max(R0, R_max);
    }
};