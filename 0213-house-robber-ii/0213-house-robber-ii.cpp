class Solution {
public:
    int f(vector<int> nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = 0;        
        int prev = nums[0];   
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notpick = prev;
            int curi = max(pick, notpick);
            prev2 = prev; 
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int> nums) {
        vector<int> t1,t2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i =0;i<n-1;i++){
            t1.push_back(nums[i]);
        }
        for(int i =1;i<n;i++){
            t2.push_back(nums[i]);
        }
        return max(f(t1),f(t2));

    }
};