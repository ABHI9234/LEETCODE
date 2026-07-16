class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int i =0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        int mx = INT_MIN;
        while(j<n){   
            sum+=nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]]>1){
                sum-=nums[i];
                mp[nums[i]]--;
                
                i++;
            }
            mx = max(sum,mx);
            j++;
        }
        return mx;
    }
};