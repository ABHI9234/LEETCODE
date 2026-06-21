class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        while(!pq.empty()) {
            auto [d, u, streak] = pq.top();
            pq.pop();
            if (d > dist[u][streak]) continue;
            if (u == n - 1) return d;
            for(auto& [v, w] : adj[u]) {
                int new_streak = (labels[u] == labels[v]) ? streak + 1 : 1;
                if (new_streak > k) continue;
                if (d + w < dist[v][new_streak]) {
                    dist[v][new_streak] = d + w;
                    pq.push({d + w, v, new_streak});
                }
            }
        }
        return -1; 
    }
};