class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        
        long long sum_a = 0; 
        long long sum_b = 0; 
        
        int min_a = INT_MAX; 
        int min_b = INT_MAX;
        
        // Edge case: If devices only have 1 unit, they don't have a second smallest
        if (n == 1) {
            for (int i = 0; i < m; i++) {
                sum_a += units[i][0];
            }
            return sum_a;
        }
        
        for (int i = 0; i < m; i++) {
            // Sort the current row
            sort(units[i].begin(), units[i].end());
            
            int a = units[i][0]; // Smallest
            int b = units[i][1]; // Second smallest
            
            // Accumulate tracking variables
            sum_a += a;
            sum_b += b;
            min_a = min(min_a, a);
            min_b = min(min_b, b);
        }
        
        // Calculate the maximum possible sum after transfers
        long long R_max = sum_b - min_b + min_a;
        
        // Return the max between doing nothing (sum_a) and optimal transfers (R_max)
        return max(sum_a, R_max);
    }
};