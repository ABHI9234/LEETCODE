class Solution {
public:
    typedef pair<int,int> pi;
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pi> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k =0;k<m;k++){
                matrix[i][k]=0;
            }
            for(int k =0;k<n;k++){
                matrix[k][j]=0;
            }
        }
    }
};