class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;
        int n = nums1.size();
        queue<pair<vector<int>, int>> q;
        set<vector<int>> visited;        
        q.push({nums1, 0});
        visited.insert(nums1);
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    vector<int> sub(curr.begin() + i, curr.begin() + j + 1);                    
                    vector<int> rem;
                    for (int k = 0; k < i; k++) rem.push_back(curr[k]);       // Left of subarray
                    for (int k = j + 1; k < n; k++) rem.push_back(curr[k]);   // Right of subarray
                    for (int k = 0; k <= rem.size(); k++) {
                        vector<int> next_state = rem;
                        next_state.insert(next_state.begin() + k, sub.begin(), sub.end());
                        if (visited.find(next_state) == visited.end()) {
                            if (next_state == nums2) {
                                return steps + 1;
                            }
                            visited.insert(next_state);
                            q.push({next_state, steps + 1});
                        }
                    }
                }
            }
        }
        
        return -1; // Return -1 if transformation is impossible
    }
};