class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1) return 0;
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    if(dist[nr][nc]>dist[r][c]+1){
                        dist[nr][nc] = dist[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = true;
        while (!pq.empty()) {
            int safe = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == n - 1 && c == n - 1) return safe;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc]==-1) {
                    int new_safe = min(safe, dist[nr][nc]);
                    pq.push({new_safe, {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return 0;
    }
};