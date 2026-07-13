class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long total_count = 0;
        int n = nums.size();
        unordered_map<int, long long> mod_freq;
        mod_freq[0] = 1; 
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % k; 
            total_count += mod_freq[mod];
            mod_freq[mod]++;
        }
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            long long C = j - i; 
            long long x = nums[i]; 
            for (long long L = 1; L <= C; L++) {
                if ((L * x) % k == 0) {
                    total_count -= (C - L);
                }
            }
            i = j; 
        }        
        return total_count;
    }
};