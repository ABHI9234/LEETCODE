class Solution {
public:
    typedef pair<int,int> pi;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==m-1 && c==n-1){
                return d<health;
            }
            if (d > dist[r][c]) continue;
            for(int i =0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 & nc<n){
                    int next_damage = d+grid[nr][nc];
                    if (next_damage < health && next_damage < dist[nr][nc]) {
                        dist[nr][nc] = next_damage;
                        pq.push({next_damage, {nr, nc}});
                    }
                }
            }
        }
        return false;
    }
};