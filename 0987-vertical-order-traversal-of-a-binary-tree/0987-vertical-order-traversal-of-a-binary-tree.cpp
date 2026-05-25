class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) return {};

        // Queue stores: {current_node, {col_coordinate, row_coordinate}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        // Map stores: col -> vector of pairs: {row, value}
        unordered_map<int, vector<pair<int, int>>> mp;
        
        q.push({root, {0, 0}});
        
        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();

            // Store both the row depth and the value together
            mp[col].push_back({row, temp->val});
            
            // Track column boundaries for the output loops
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            if (temp->left) {
                q.push({temp->left, {col - 1, row + 1}});
            }
            if (temp->right) {
                q.push({temp->right, {col + 1, row + 1}});
            }
        }

        vector<vector<int>> ans;
        
        // Step from leftmost column to rightmost column
        for (int i = minCol; i <= maxCol; i++) {
            if (mp.find(i) != mp.end()) {
                // 1. Sort the vector of pairs. 
                // This sorts by row first, and breaks ties by value!
                sort(mp[i].begin(), mp[i].end());
                
                // 2. Extract just the values out of the sorted pairs into a clean vector
                vector<int> sortedCol;
                for (auto& p : mp[i]) {
                    sortedCol.push_back(p.second); // p.second is the node value
                }
                
                ans.push_back(sortedCol);
            }
        }
        
        return ans;
    }
};