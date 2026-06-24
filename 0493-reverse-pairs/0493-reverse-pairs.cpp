class Solution {
    int solve(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;  
        int mid = low + (high - low) / 2;
        int count = 0;
        count += solve(nums, low, mid);
        count += solve(nums, mid + 1, high);
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        sort(nums.begin() + low, nums.begin() + high + 1);        
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};