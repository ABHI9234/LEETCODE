class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long MOD =1000000007;
        long long x  = 1;
        long long y = k;
        long long n = nums.size();
        long long sum = 0;
        for(int i =0;i<n;i++){
            if(y>=nums[i]) y -=nums[i];
            else{
                long long diff = nums[i]-y;
                long long op = ((diff+k-1)/k);
                long long part1 = (op % MOD * x % MOD) % MOD;
                long long part2 = ((op  * (op - 1))/ 2) % MOD;
                sum = (sum + part1 + part2) % MOD;
                y = y+k*op;
                y-=nums[i];
                x=(x+op)%MOD;
            }
        }
        return (int)(sum%MOD);
    }
};