class Solution {
    vector<pair<int,int>> directions = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool isValid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0;i<m;i++) {
            for(int j=0;j< n;j++) {
                if(grid[i][j] == 0)
                    q.push({0, i, j});
            }
        }

        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            int row = curr[1];
            int col = curr[2];
            int value = curr[0];
            vis[row][col] = true;
            grid[row][col] = min(grid[row][col], value);

            for(auto dir: directions){
                int new_x = dir.first + row;
                int new_y = dir.second + col;
                if(isValid(new_x, new_y, m, n) && !vis[new_x][new_y] && grid[new_x][new_y] != -1)
                    q.push({value+1, new_x, new_y});
            }
        }
        return;
    }
};
