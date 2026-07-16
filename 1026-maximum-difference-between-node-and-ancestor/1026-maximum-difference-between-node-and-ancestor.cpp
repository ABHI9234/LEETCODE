class Solution {
public:

    int dfs(TreeNode* node, int cur_min, int cur_max) {
        if (node == nullptr) {
            return cur_max - cur_min;
        }        
        cur_min = min(cur_min, node->val);
        cur_max = max(cur_max, node->val);
        int left_diff = dfs(node->left, cur_min, cur_max);
        int right_diff = dfs(node->right, cur_min, cur_max);
        return max(left_diff, right_diff);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};