class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int> a;
        int n = nums.size();
        a.push_back(nums[0]);
        for(int i =1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            else a.push_back(nums[i]);
        }
        n = a.size();
        int lo = 0;
        int hi = n-1;
        int mid = lo+(hi-lo)/2;
        int ans = INT_MAX;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(a[lo]<=a[mid]){
                ans = min(ans,a[lo]);
                lo = mid+1;
            }
            else{
                ans = min(ans,a[mid]);
                hi = mid-1;
            }
        }
        return ans;
    }
};