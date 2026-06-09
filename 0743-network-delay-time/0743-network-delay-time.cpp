class Solution {
public:
    typedef pair<int,int> pi;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pi>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n+1,1e9);
        priority_queue<pi,vector<pi>,greater<pi>> pq; // dis,node
        pq.push({0,k});
        dis[k]=0;
        while(pq.size()>0){
            int node = pq.top().second;
            int disn = pq.top().first;
            pq.pop();
            for(auto x:adj[node]){
                int ne = x.first;
                int c = x.second;
                if(c+disn<dis[ne]){
                    pq.push({c+disn,ne});
                    dis[ne] = c+disn;
                }
            }
        }
        int maxtime = 0;
        for(int i =1;i<n+1;i++){
            if(dis[i]==1e9) return -1;
            maxtime = max(maxtime,dis[i]);
        }
        return maxtime;
    }
};