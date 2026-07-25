class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> ans(n, false);
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        vector<int> reachable_sums;
        reachable_sums.push_back(0);
        int idx = 0;
        for (int x = 1; x <= n; x++) {
            while (idx < n && nums[idx] < x) {
                int val = nums[idx];
                int current_size = reachable_sums.size();
                for (int i = 0; i < current_size; i++) {
                    int S = reachable_sums[i];
                    if (S + val <= k && !dp[S + val]) {
                        dp[S + val] = true;
                        reachable_sums.push_back(S + val);
                    }
                }
                idx++;
            }
            int count_of_x = n - idx; 
            for (int S : reachable_sums) {
                int needed = k - S;
                if (needed >= 0 && needed % x == 0 && (needed / x) <= count_of_x) {
                    ans[x - 1] = true;
                    break;
                }
            }
        }
        
        return ans;
    }
};