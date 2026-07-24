class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sumEven = 0; 
        long long sumOdd = 0;
        for (int num : nums) {
            long long nextEven = max(sumEven, sumOdd + num);
            long long nextOdd = max(sumOdd, sumEven - num);
            sumEven = nextEven;
            sumOdd = nextOdd;
        }
        return sumEven; 
    }
};