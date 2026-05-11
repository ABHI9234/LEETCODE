class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, last = -1; // Initialize with -1 for "not found"

        // 1. Find First Occurrence
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) first = mid; // Only update if it's the target
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // 2. Find Last Occurrence
        lo = 0; hi = n - 1; // Reset pointers
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) last = mid; // Only update if it's the target
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return {first, last};
    }
};