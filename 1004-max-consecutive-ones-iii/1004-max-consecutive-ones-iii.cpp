class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        int maxlen = 0; 
        
        int x = 0; 
        
        while (j < n) {
            
           
            if (nums[j] == 0) {
                x++; 
            }

     
            while (x > k) {
                if (nums[i] == 0) {
                    x--; 
                }
                i++; 
            }
            maxlen = max(maxlen, j - i + 1);

            j++; 
        }

        return maxlen;
    }
};