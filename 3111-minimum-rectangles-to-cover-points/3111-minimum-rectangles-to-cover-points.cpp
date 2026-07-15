class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& nums, int w) {
        int c = 0;
        sort(nums.begin(),nums.end());
        int end = -1;
        for(auto it:nums){
            if(end==-1 || it[0]>end){
                c++;
                end = it[0]+w;
            }
        }
        return c;
    }
};