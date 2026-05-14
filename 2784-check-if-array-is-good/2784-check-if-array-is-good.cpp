class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool flag = false;
        int n = nums.size();
        if(n==1) return false;
        if(nums[n-1]==nums[n-2] && nums[n-1]==n-1) flag = true;
        bool f = true;
        for(int i =0;i<n-2;i++){
            if(nums[i]!=i+1){
                f = false;
                break;
            }
        }
        return (flag && f);
    }
};