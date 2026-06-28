class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long sum =0;
        sort(nums.begin(),nums.end(),greater<int>());
        int i = 0;
        while(k>0 && mul>0){
            sum+=(long long)(nums[i])*mul;
            k--;
            mul--;
            i++;
        }
        if(k>0){
            while(k>0){
                sum+=(long long)(nums[i]);
                i++;
                k--;
            }
        }
        return sum;
    }
};