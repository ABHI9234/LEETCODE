class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]!=1) dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int m = connections.size();
        int s=0;
        for(int i =0;i<n;i++){
            if(vis[i]!=1){
                dfs(i,adj,vis);
                s++;
            }
        }
        if(m<n-1) return -1;
        return s-1;
        
    }
};