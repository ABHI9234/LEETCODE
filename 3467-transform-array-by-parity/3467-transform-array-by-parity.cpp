class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int x = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==0) x++;
        }
        vector<int>v(nums.size(),0);
        for(int i =x;i<nums.size();i++) v[i]=1;
        return v;
    }
};