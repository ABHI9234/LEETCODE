class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> pq;
        vector<int> max_power_seen(n, -1);
        pq.push({0, -power, source});
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            long long t = current[0];
            int p = -current[1]; 
            int u = current[2];
            if (p <= max_power_seen[u]) {
                continue;
            }
            max_power_seen[u] = p;
            if (u == target) {
                return {t, (long long)p};
            }
            if (p < cost[u]) {
                continue;
            }
            int next_power = p - cost[u];
            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                long long weight = neighbor.second;
                if (next_power > max_power_seen[v]) {
                    pq.push({t + weight, -next_power, v}); 
                }
            }
        }

        return {-1, -1};
    }
};