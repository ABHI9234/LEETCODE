class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>& graph,vector<int>& color){
        color[node] = col;
        for(auto it: graph[node]){
            if(color[it]==-1){
                if(dfs(it,!col,graph,color)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
    // bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         int m = graph[0].size();
//         vector<int> color(n,-1);
//         // for(int i =0;i<n;i++){
//         //     if(color[i]==-1){
//         //         if(dfs(i,0,graph,color)==false) return false;
//         //     }
//         // }
//         //bfs
//         queue<int> q;
//         q.push(0);
//         color[0] = 0;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             for(auto it: graph[node]){
//                 if(color[it]==-1){
//                     color[it] = !color[node];
//                     q.push(it);
//                 }
//                 else if(color[it]==color[node]) return false;

//             }
//         }
//         return true;
//     }
// };

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    
    // Array to store colors of nodes. 
    // -1 means uncolored, 0 means Color A, 1 means Color B.
    vector<int> colors(n, -1);
    
    // We loop through all nodes to ensure we cover disconnected components
    for (int start_node = 0; start_node < n; ++start_node) {
        // If the node is uncolored, initiate BFS from here
        if (colors[start_node] == -1) {
            queue<int> q;
            q.push(start_node);
            colors[start_node] = 0;  // Assign the starting color (0)
            
            while (!q.empty()) {
                int current_node = q.front();
                q.pop();
                
                // Check all adjacent neighbors
                for (int neighbor : graph[current_node]) {
                    // If the neighbor is uncolored, color it with the opposite color
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[current_node];
                        q.push(neighbor);
                    }
                    // If the neighbor has the same color as the current node, it's not bipartite
                    else if (colors[neighbor] == colors[current_node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
};















