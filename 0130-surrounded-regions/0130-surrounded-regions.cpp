class Solution {
public:
    void dfs(int i ,int j , vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {-1,1,0,0};
         int m = board.size();
        int n = board[0].size();
        for(int x = 0;x<4;x++){
            int nr = i+dr[x];
            int nc = j+dc[x];
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==-1 && board[nr][nc]=='O'){
                vis[nr][nc] = 1;
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        for(int i =0;i<n;i++){
            if(board[0][i]=='O') dfs(0,i,board,vis);
            if(board[m-1][i]=='O') dfs(m-1,i,board,vis);
        }
        for(int i =0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board,vis);
            if(board[i][n-1]=='O') dfs(i,n-1,board,vis);
        }
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]==-1) board[i][j] = 'X';
            }
        }
    }
};