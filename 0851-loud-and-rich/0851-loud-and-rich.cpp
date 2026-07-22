class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj,vector<int>& quiet,vector<int>& ans){
        if(ans[node]!=-1) return ans[node];
        int q = node;
        for(auto it:adj[node]){
            int candidate = dfs(it, adj, quiet, ans);
            if (quiet[candidate] < quiet[q]) {
                q = candidate;
            }
        }
        return ans[node] = q;

    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n,-1);
        vector<vector<int>> adj(n);
        for(auto it: richer){
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, adj, quiet, ans);
        }
        return ans;
    }
};