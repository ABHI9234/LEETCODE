class Solution {
public:
    // bool dfs(int node,vector<int>& vis,vector<vector<int>>& adj,int target){
    //     vis[node]=1;
    //     if(node==target) return true;
    //     for(auto it: adj[node]){
    //         if(it==target) return true;
    //         if(vis[it]==-1){
    //             vis[it]=1;
    //             if(dfs(it,vis,adj,target)) return true;
    //         }
    //     }
    //     return false;
    // }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // vector<vector<int>> adj(n);
        // for(int i =0;i<n;i++){
        //     for(int j =i;j<n;j++){
        //         if(nums[j]-nums[i]<=maxDiff){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        // vector<bool> ans;
        // for(auto it: queries){
        //     int x = it[0];
        //     int y = it[1];
        //     vector<int> vis(n,-1);
        //     bool f = dfs(x,vis,adj,y);
        //     ans.push_back(f);
        // }
        // return ans;
        // g[i] will store the "Component ID" for the node at index i
        vector<int> g(n, 0);
        int current_component = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_component++;
            }
            g[i] = current_component;
        }
        int m = queries.size();
        vector<bool> ans;
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            ans.push_back(g[u] == g[v]);
        }
        return ans;
    }
};