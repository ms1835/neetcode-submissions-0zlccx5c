class Solution {
    vector<pair<int,int>> directions = {
        {0,1}, {1,0}, {-1,0}, {0,-1}
    };

    void dfs(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &vis, bool mark){
        vis[row][col] = true;
        if(mark)
            board[row][col] = 'X';
        for(auto &dir: directions){
            int x = row + dir.first;
            int y = col + dir.second;
            if(x>=0 && y>=0 && x<board.size() && y<board[0].size() &&
            board[x][y] == 'O' && !vis[x][y])
                dfs(board, x,y,vis, mark);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i == m-1 || j == n-1) && board[i][j] == 'O')
                    dfs(board, i, j, vis, false);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !vis[i][j])
                    dfs(board, i, j, vis, true);
            }
        }
    }
};
