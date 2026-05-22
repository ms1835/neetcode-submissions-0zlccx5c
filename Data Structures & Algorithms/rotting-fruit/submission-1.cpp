class Solution {
    vector<pair<int,int>> directions = {
        {0,1}, {1,0}, {-1,0}, {0,-1}
    };

    bool isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        int freshFruits = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    freshFruits++;
            }
        }

        int time = 0;
        while(freshFruits > 0 && !q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int,int> curr = q.front();
                q.pop();
                for(auto direction: directions){
                    int new_x = direction.first + curr.first;
                    int new_y = direction.second + curr.second;
                    if(isValid(new_x, new_y, m,n) && grid[new_x][new_y] == 1){
                        freshFruits--;
                        q.push({new_x, new_y});
                        grid[new_x][new_y] = 2;
                    }
                }
            }
            time++;
        }
        return freshFruits == 0 ? time : -1;
    }
};
