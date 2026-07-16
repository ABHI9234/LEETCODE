class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        vector<int> pgcd;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            pgcd.push_back(gcd(nums[i],mx));
        }
        sort(pgcd.begin(),pgcd.end());
        long long sum =0;
        for(int i =0;i<n/2;i++){
            sum+=(long long)gcd(pgcd[i],pgcd[n-1-i]);
        }
        return sum;
    }
};