class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& nums, int freeStart, int freeEnd) {
        vector<vector<int>> merged;
        sort(nums.begin(),nums.end());
        merged.push_back(nums[0]);
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i][0]<=merged[merged.size()-1][1]+1){
                merged[merged.size()-1][1] = max(merged[merged.size()-1][1],nums[i][1]);
            }
            else merged.push_back(nums[i]);
        }
        vector<vector<int>> ans;
        
        for(int i = 0; i < merged.size(); i++){
            int start = merged[i][0];
            int end = merged[i][1];
            if(end < freeStart || start > freeEnd) {
                ans.push_back({start, end});
            } 
            else {
                if(start < freeStart){
                    ans.push_back({start, freeStart - 1});
                }
                if(end > freeEnd){
                    ans.push_back({freeEnd + 1, end});
                }
            }
        }
        return ans;
    }
};