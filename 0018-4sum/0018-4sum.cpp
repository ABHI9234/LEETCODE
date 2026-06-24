class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;        
        if (n < 4) return result; 
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue; 
                int lo = j + 1;
                int hi = n - 1;
                while(lo < hi) {
                    long long sum = (long long)nums[i] + nums[j] + nums[lo] + nums[hi];
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;                        
                        lo++;
                        hi--;
                    }
                    else if(sum < target) lo++;
                    else hi--;
                }
            }
        }
        return result;
    }
};