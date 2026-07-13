class Solution {
public:
    long long countStableSubarrays(vector<int>& nums) {
        long long c = 0;
        int n = nums.size();
        if (n < 3) return 0;
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] + nums[i];
        unordered_map<long long, unordered_map<long long, long long>> freq;
        for(int j = 2; j < n; j++){
            int i = j - 2;
            long long target = pre[i] + nums[i];
            freq[nums[i]][target]++;
            c += freq[nums[j]][pre[j-1]];
        }
        return c;
    }
};