// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
//         if (state[node] != 0)
//             return state[node] == 2;
//         state[node] = 1;
//         for (int nei : graph[node]) {
//             if (!dfs(nei, graph, state))
//                 return false;
//         }
//         state[node] = 2; 
//         return true;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> state(n, 0);
//         vector<int> ans;
//         for (int i = 0; i < n; i++) {
//             if (dfs(i, graph, state))
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // revGraph will store the reversed edges
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);
        
        // 1. Reverse the graph and calculate the new indegrees
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                revGraph[it].push_back(i);
                indegree[i]++; // The outdegree of the original is the indegree of the reversed
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        
        // 2. Start with nodes that have an indegree of 0 in the reversed graph (Terminal Nodes)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        // 3. Process the queue (Kahn's Algorithm)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (auto x : revGraph[node]) {
                indegree[x]--;
                if (indegree[x] == 0) q.push(x);
            }
        }
        
        // 4. The problem strictly requires the result to be sorted in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};