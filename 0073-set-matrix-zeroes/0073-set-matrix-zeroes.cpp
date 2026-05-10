class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        stack<pair<int,int>> st;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) st.push({i,j});
            }
        }
        while(st.size()>0){
            int x = st.top().first;
            int y = st.top().second;
            for(int i=0;i<m;i++){
                matrix[x][i]=0;
            }
            for(int i=0;i<n;i++){
                matrix[i][y]=0;
            }
            st.pop();
        }

    }
};