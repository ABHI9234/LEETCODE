class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int currsum = nums[0];
        int mxsum = nums[0];
        vector<long long> pre(nums.size());
        pre[0] = nums[0];
        int c = 0;
        if(pre[0]>0) c++;
        for(int i =1;i<nums.size();i++){
            pre[i] = pre[i-1]+(long long)(nums[i]);
            if(pre[i]>0) c++;
        }
        return c;
    }
};