class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        int lo = 1;

        int hi = 0;
        for(int i =0;i<n;i++){
            if(nums[i]>hi) hi = nums[i];
        }
        int mid = lo+(hi-lo)/2;
        int x = hi;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            long long ans =0;
            for (int i = 0; i < n; i++) {
                ans += (nums[i] + (long long)mid - 1) / mid;
            }
            if(ans<=h){
                x=mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return x;
    }
};