class Solution {
    vector<pair<int,int>> directions = {
        {0,1}, {1,0}, {-1,0}, {0,-1}
    };

    bool isValid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }

    void dfs(vector<vector<int>> &heights, int row, int col,
    vector<vector<bool>> &vis){
        vis[row][col] = true;

        for(auto dir: directions){
            int new_x = dir.first + row;
            int new_y = dir.second + col;
            if(isValid(new_x, new_y, heights.size(), heights[0].size()) && 
            !vis[new_x][new_y] && heights[new_x][new_y] >= heights[row][col])
                dfs(heights, new_x, new_y, vis);
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pvis(m, vector<bool>(n, false));
        vector<vector<bool>> avis(m, vector<bool>(n, false));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i ==0 || j == 0) {
                    dfs(heights, i, j, pvis);
                }
                if(i == m-1 || j == n-1)
                    dfs(heights, i, j, avis);
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(avis[i][j] && pvis[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
