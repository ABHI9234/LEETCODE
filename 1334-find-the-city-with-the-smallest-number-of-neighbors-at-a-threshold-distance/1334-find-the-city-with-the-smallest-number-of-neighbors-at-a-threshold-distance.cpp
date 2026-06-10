class Solution {
public:
    typedef pair<int,int> pi;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            matrix[u][v] = weight;
            matrix[v][u] = weight;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int minNeighborCount = n; // Max possible neighbors is n-1, so 'n' is a safe infinity
        int ansCity = -1;

        for (int i = 0; i < n; i++) {
            int currentCityCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] <= distanceThreshold) {
                    currentCityCount++;
                }
            }
            if (currentCityCount <= minNeighborCount) {
                minNeighborCount = currentCityCount;
                ansCity = i;
            }
        }

        return ansCity;

    }
};