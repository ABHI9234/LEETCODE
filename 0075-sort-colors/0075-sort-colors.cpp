class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0, 0, 0};
        
        // Count frequencies of 0, 1, and 2
        for (int x : nums) counts[x]++;
        
        // Overwrite original array
        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (counts[i] > 0) {
                nums[index++] = i;
                counts[i]--;
            }
        }
    }
};