class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pi>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
        vector<int> dis(n,-1);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});
        dis[0] = 0;
        while(!pq.empty()){
            int curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis[node]<curr) continue;
            for(auto it:adj[node]){
                int w = it.second;
                int nei = it.first;
                
                if(w+curr<disappear[nei]){
                    if(dis[nei]==-1 || dis[nei]>w+curr){
                        pq.push({w+curr,nei});
                        dis[nei] = w+curr;}
                }
            }
        }
        return dis;
    }
};