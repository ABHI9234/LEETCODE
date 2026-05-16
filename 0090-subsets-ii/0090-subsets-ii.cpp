class Solution {
public:
    void z(vector<int> &nums, vector<vector<int>> &s, int index, vector<int> &v) {
        s.push_back(v);        
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            v.push_back(nums[i]);
            z(nums, s, i + 1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<vector<int>> s;
        z(nums, s, 0, v);
        return s;
    }
};