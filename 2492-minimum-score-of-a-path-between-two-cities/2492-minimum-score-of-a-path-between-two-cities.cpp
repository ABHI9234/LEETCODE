class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        queue<int> q;
        q.push(1);
        vector<int> vis(n+1,-1);
        vis[1] = 1;
        int mn = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;
                mn = min(mn, weight);
                if (vis[neighbor]!=1) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        return mn;
    }
};