class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int j =0;
        int count =0;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                count+=(n-i);
                j++;
            }
        }
        
        j =0;
        int c=0;
        mp.clear();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>k-1){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                c+=(n-i);
                j++;
            }
        }
        return abs(count-c);
    }
};