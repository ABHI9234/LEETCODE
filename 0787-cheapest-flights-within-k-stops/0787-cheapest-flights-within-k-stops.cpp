class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k) continue;
            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int price = edge.second;
                if (cost + price < dist[neighbor]) {
                    dist[neighbor] = cost + price;
                    q.push({stops + 1, {neighbor, dist[neighbor]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};