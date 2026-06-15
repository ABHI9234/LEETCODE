class Solution {
    int maxMemo[100005];
    int minMemo[100005];
    bool visitedMax[100005] = {false};
    bool visitedMin[100005] = {false};

    // dp[i]: Max subarray sum ending at index i
    int getMaxEndingHere(int i, const vector<int>& nums) {
        if (i < 0) return 0;
        if (visitedMax[i]) return maxMemo[i];
        
        // Option 1: "Pick" the previous subarray sum to continue the chain
        int pick_prev = nums[i] + getMaxEndingHere(i - 1, nums);
        
        // Option 2: "Not pick" the previous sum, start a fresh chain here
        int not_pick_prev = nums[i];
        
        visitedMax[i] = true;
        return maxMemo[i] = max(pick_prev, not_pick_prev);
    }

    // dp[i]: Min subarray sum ending at index i
    int getMinEndingHere(int i, const vector<int>& nums) {
        if (i < 0) return 0;
        if (visitedMin[i]) return minMemo[i];
        
        // Option 1: "Pick" the previous subarray sum
        int pick_prev = nums[i] + getMinEndingHere(i - 1, nums);
        
        // Option 2: "Not pick" the previous sum, start a fresh chain here
        int not_pick_prev = nums[i];
        
        visitedMin[i] = true;
        return minMemo[i] = min(pick_prev, not_pick_prev);
    }

public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        
        int globalMax = 0;
        int globalMin = 0;
        
        // We must check every index as a potential ending point for our subarray
        for (int i = 0; i < n; i++) {
            globalMax = max(globalMax, getMaxEndingHere(i, nums));
            globalMin = min(globalMin, getMinEndingHere(i, nums));
        }
        
        return max(globalMax, abs(globalMin));
    }
};