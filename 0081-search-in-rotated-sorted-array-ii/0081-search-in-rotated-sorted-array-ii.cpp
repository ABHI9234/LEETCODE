class Solution {
public:
    int s(vector<int>& nums, int target){
        int n = nums.size();
        int lo =0;
        int hi = n-1;
        int mid = lo+(hi-lo)/2;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
                continue;
            }
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && nums[mid]>=target){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[hi]>=target){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int x = s(nums,target);
        if(x!=-1) return true;
        return false;
    }
};