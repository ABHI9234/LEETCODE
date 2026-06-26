class Solution {
public:
    void sum(vector<vector<int>> &ans,vector<int> &v,vector<int>& nums,int target,int i,int s,int k){
        if(s==target && v.size()==k){
            ans.push_back(v);
            return;
        }
        if(i==nums.size()||s>target) return;
        s+=nums[i];
        v.push_back(nums[i]);
        sum(ans,v,nums,target,i+1,s,k);
        v.pop_back();
        s-=nums[i];
        sum(ans,v,nums,target,i+1,s,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        vector<vector<int>> ans;
        for(int i =0;i<=8;i++){
            nums[i] = i+1;
        }
        vector<int> v;
        sum(ans,v,nums,n,0,0,k);
        return ans;

    }
};