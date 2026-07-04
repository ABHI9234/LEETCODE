class Solution {
    public:
        unordered_map<int, vector<int>> adj;
        void buildGraph(TreeNode* node, TreeNode* parent) {
            if (!node) return;
            if (parent) {
                adj[node->val].push_back(parent->val);
                adj[parent->val].push_back(node->val);
            }
            buildGraph(node->left, node);
            buildGraph(node->right, node);
        }
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            buildGraph(root, nullptr);
            vector<int> ans;
            queue<int> q;
            unordered_set<int> visited;
            q.push(target->val);
            visited.insert(target->val);
            int current_distance = 0;
            while (!q.empty()) {
                if (current_distance == k) {
                    while (!q.empty()) {
                        ans.push_back(q.front());
                        q.pop();
                    }
                    return ans;
                }
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int curr = q.front();
                    q.pop();
                    for (int neighbor : adj[curr]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                current_distance++;
            }
            return ans;
    }
};