class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int currentRank = 1;
        for (int num : nums) {
            if (mp.find(num) == mp.end()) {
                mp[num] = currentRank;
                currentRank++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};