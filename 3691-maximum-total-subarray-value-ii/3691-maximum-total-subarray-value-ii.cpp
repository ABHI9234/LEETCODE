// class Solution {
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
//         int mxidx = 0;
//         int mnidx = 0;
//         int n = nums.size();
//         set<pair<int,int>> stmi;
//         set<pair<int,int>> stmx;
//         while(k>0){
//             int mn = INT_MAX;
//             int mx = INT_MIN;
//             for(int i =0;i<n;i++){
//                 if(nums[i]<=mn){
//                     mn = nums[i];
//                     mnidx = i;
//                 }
//                 if(nums[i]>=mx){
//                     mx = nums[i];
//                     mxidx = i;
//                 }
//             }
//             int mnn,mni,mxx,mxi;
//             if(stmi.find({mn,mnidx})==stmi.end()){
//                 mnn = mn;
//                 mni = mnidx;
//                 stmi.insert({mn,mnidx});
//             }
            
//             if(stmx.find({mx,mxidx})==stmx.end()){
//                 mxx = mx;
//                 mxi = mxidx;
//                 stmx.insert({mx,mxidx});
//             }
//             long long c =0;
//             if(mni<mxi){
//                 c = (mni+1) * (n-mxi);
//             }
//             else{
//                 c = (mxi+1) * (n-mni);
//             }
//             long long sum = 0;
//             if(c>=k) return (1LL*k)*((1LL*mxx)-(1LL*mnn));
//             else{
//                 sum+=(1LL*k)*((1LL*mx)-(1LL*mn));
//                 k -=c; 
//             }
//         }
//          return 0;
//     }
// };


class Solution {
    int maxLog;
    vector<vector<int>> fMax;
    vector<vector<int>> fMin;
    vector<int> lg;

    // O(1) query for maximum in range [l, r]
    int queryMax(int l, int r) {
        int j = lg[r - l + 1];
        return max(fMax[l][j], fMax[r - (1 << j) + 1][j]);
    }

    // O(1) query for minimum in range [l, r]
    int queryMin(int l, int r) {
        int j = lg[r - l + 1];
        return min(fMin[l][j], fMin[r - (1 << j) + 1][j]);
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. Precompute logs for O(1) range queries
        maxLog = 32 - __builtin_clz(n) + 1;
        fMax.assign(n, vector<int>(maxLog));
        fMin.assign(n, vector<int>(maxLog));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }

        // 2. Build the Sparse Table
        for (int i = 0; i < n; i++) {
            fMax[i][0] = nums[i];
            fMin[i][0] = nums[i];
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                fMax[i][j] = max(fMax[i][j - 1], fMax[i + (1 << (j - 1))][j - 1]);
                fMin[i][j] = min(fMin[i][j - 1], fMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        // 3. Priority Queue to store {value, left_idx, right_idx}
        // max-heap by default in C++
        priority_queue<tuple<int, int, int>> pq; 
        
        // Push the maximum possible subarray for each starting index 'l'
        for (int i = 0; i < n; i++) {
            int val = queryMax(i, n - 1) - queryMin(i, n - 1);
            pq.push({val, i, n - 1});
        }

        long long ans = 0;
        
        // 4. Greedily pick the top k subarrays
        while (k > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();
            
            ans += val;
            k--;
            
            // The next best subarray starting at 'l' is the one ending at 'r - 1'
            if (r > l) {
                int nextVal = queryMax(l, r - 1) - queryMin(l, r - 1);
                pq.push({nextVal, l, r - 1});
            }
        }

        return ans;
    }
};
