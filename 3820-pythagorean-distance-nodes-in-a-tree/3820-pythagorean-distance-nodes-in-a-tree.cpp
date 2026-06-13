// class Solution {
// public:
//     bool pytha(int a, int b, int c) {
//         long long x = a, y = b, z = c;
//         long long total = x + y + z;
//         long long mn = min({x, y, z});
//         long long mx = max({x, y, z});
//         long long mid = total - mn - mx; 
//         return mn * mn + mid * mid == mx * mx;
//     }
//     void dfs(int node, int parent, int dist,vector<vector<int>>& adj,vector<int>& d) {
//         d[node] = dist;
//         for (int nei : adj[node]) {
//             if (nei != parent) {
//                 dfs(nei, node, dist + 1, adj, d);
//             }
//         }
//     }
//     int specialNodes(int n, vector<vector<int>>& edges,int x, int y, int z) {
//         vector<vector<int>> adj(n);
//         for (auto &e : edges) {
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }
//         vector<int> distX(n), distY(n), distZ(n);
//         dfs(x, -1, 0, adj, distX);
//         dfs(y, -1, 0, adj, distY);
//         dfs(z, -1, 0, adj, distZ);
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (pytha(distX[i], distY[i], distZ[i])) {
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

// BFS

class Solution {
public:
    bool pytha(int a, int b, int c) {
        long long x = a, y = b, z = c;
        long long total = x + y + z;
        long long mn = min({x, y, z});
        long long mx = max({x, y, z});
        long long mid = total - mn - mx; 
        
        return mn * mn + mid * mid == mx * mx;
    }
    void bfs(int start, int n, vector<vector<int>>& adj, vector<int>& dist) {
        queue<int> q;
        q.push(start);
        dist[start] = 0; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> distX(n, -1), distY(n, -1), distZ(n, -1);
        bfs(x, n, adj, distX);
        bfs(y, n, adj, distY);
        bfs(z, n, adj, distZ);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (pytha(distX[i], distY[i], distZ[i])) {
                ans++;
            }
        }
        return ans;
    }
};