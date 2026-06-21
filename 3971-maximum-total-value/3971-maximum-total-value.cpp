class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();
        
        // Helper function to count how many total picks give a value >= x
        auto get_count = [&](long long x) {
            long long c = 0;
            for (int i = 0; i < n; i++) {
                if (value[i] >= x) {
                    c += (value[i] - x) / decay[i] + 1;
                }
            }
            return c;
        };

        // Binary Search range for the threshold value X
        long long low = 1;
        long long high = *max_element(value.begin(), value.end());
        long long X = 0;
        
        // If taking ALL positive values results in > m picks, find the optimal cutoff X
        if (get_count(1) > m) {
            long long ans = 1;
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                if (get_count(mid) >= m) {
                    ans = mid;
                    low = mid + 1; // Try to find a higher valid threshold
                } else {
                    high = mid - 1; // Threshold is too high, it gives < m picks
                }
            }
            X = ans;
        }
        
        long long total_sum = 0;
        long long mod = 1e9 + 7;
        long long count_strictly_greater = 0;
        
        // We first sum up all picks that yield strictly MORE than our threshold X
        long long threshold = X + 1; 
        
        for (int i = 0; i < n; i++) {
            if (value[i] >= threshold) {
                // Number of valid picks for this item
                long long k = (value[i] - threshold) / decay[i] + 1;
                count_strictly_greater += k;
                
                // First and Last values in the arithmetic progression
                long long a = value[i];
                long long l = value[i] - (k - 1) * decay[i];
                
                // Sum of Arithmetic Progression: k * (a + l) / 2
                // Note: k * (a + l) fits comfortably in a signed 64-bit int before division
                long long current_sum = (k * (a + l) / 2) % mod;
                total_sum = (total_sum + current_sum) % mod;
            }
        }
        
        // Pad the remaining picks with exactly the threshold value X
        long long needed = m - count_strictly_greater;
        if (needed > 0 && X > 0) {
            long long add = (needed % mod) * (X % mod) % mod;
            total_sum = (total_sum + add) % mod;
        }
        
        return total_sum;
    }
};