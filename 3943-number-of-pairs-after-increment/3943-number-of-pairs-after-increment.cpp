// class Solution {
// public:
//     vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int a = queries.size();
//         vector<int> ans;
//         for(int i =0;i<a;i++){
//             int b = queries[i].size();
//             if(b==2){
//                 int c=0;
//                 for(int x =0;x<n;x++){
//                     for(int j =0;j<m;j++){
//                         if(nums1[x]+nums2[j]==queries[i][1]) c++;
//                     }
//                 }
//                 ans.push_back(c);
//             }
//             if(b==4){
//                 int l = queries[i][1];
//                 int r = queries[i][2];
//                 if(r<m){
//                     for(int x =l;x<=r;x++) nums2[x]+=queries[i][3];
//                 }
//             }
//         }
//         return ans;
//     }
// };

#pragma GCC optimize("O3", "unroll-loops")
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // 1. Prevent Integer Overflow: 
        // Copy nums2 into a 64-bit integer array to safely absorb massive cumulative additions.
        vector<long long> arr2(nums2.begin(), nums2.end());
        
        unordered_map<int, int> cnt1;
        for (int num : nums1) {
            cnt1[num]++;
        }
        
        // 2. Square Root Decomposition Setup
        int B = max(1, (int)sqrt(cnt1.size() * n2));
        int num_blocks = (n2 + B - 1) / B;
        
        vector<unordered_map<long long, int>> block_cnt(num_blocks);
        vector<long long> lazy(num_blocks, 0);
        
        for (int i = 0; i < n2; ++i) {
            block_cnt[i / B][arr2[i]]++;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            if (q.size() == 2) { 
                long long target = q[1];
                int total = 0;
                
                for (const auto& [x, c] : cnt1) {
                    for (int i = 0; i < num_blocks; ++i) {
                        long long needed = target - x - lazy[i];
                        if (block_cnt[i].count(needed)) {
                            total += block_cnt[i][needed] * c;
                        }
                    }
                }
                ans.push_back(total);
                
            } else { 
                int l = q[1];
                int r = q[2];
                long long val = q[3];
                
                int start_block = l / B;
                int end_block = r / B;
                
                // Use arr2 (long long) instead of nums2 (int)
                auto update_partial = [&](int block_idx, int start_idx, int end_idx) {
                    for (int i = start_idx; i <= end_idx; ++i) {
                        block_cnt[block_idx][arr2[i]]--;
                        if (block_cnt[block_idx][arr2[i]] == 0) {
                            block_cnt[block_idx].erase(arr2[i]);
                        }
                        arr2[i] += val;
                        block_cnt[block_idx][arr2[i]]++;
                    }
                };
                
                if (start_block == end_block) {
                    update_partial(start_block, l, r);
                } else {
                    update_partial(start_block, l, (start_block + 1) * B - 1);
                    
                    for (int i = start_block + 1; i < end_block; ++i) {
                        lazy[i] += val;
                    }
                    
                    update_partial(end_block, end_block * B, r);
                }
            }
        }
        
        return ans;
    }
};