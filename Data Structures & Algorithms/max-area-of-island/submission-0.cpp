class Solution {
    vector<pair<int,int>> directions = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };
    void solve(vector<vector<int>> &grid, int row, int col, int &res) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() 
        || grid[row][col] == 0)
            return;
        grid[row][col] = 0;
        res++;
        for(auto direction : directions) {
            int new_x = direction.first+row;
            int new_y = direction.second+col;
            solve(grid, new_x, new_y, res);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, res;
        int m = grid.size(), n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) {
                    res = 0;
                    solve(grid, i, j, res);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};
