class Solution {
public:
    typedef long long ll;
    bool ispytha(int a,int b,int c){
        ll mx = max(a,max(b,c));
        ll mi = min(a,min(b,c));
        ll mid = a+b+c-mx-mi;
        return mx*mx == mi*mi + mid*mid;
    }
    void bfs(int start,vector<int>& dis,vector<vector<int>>& adj){
        queue<int> q;
        q.push(start);
        dis[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dis[it]==-1){
                    dis[it] = dis[node]+1;
                    q.push(it);
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(int i =0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dx(n,-1),dy(n,-1),dz(n,-1);
        bfs(x,dx,adj);
        bfs(y,dy,adj);
        bfs(z,dz,adj);
        int ans=0;
        for(int i=0;i<n;i++){
            if(ispytha(dx[i],dy[i],dz[i])){
                ans++;
            }
        }
        return ans; 
    }
};