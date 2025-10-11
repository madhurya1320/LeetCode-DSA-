class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(); int c = grid[0].size(); int maxres = 0;
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == 1) {
                  maxres = max(maxres, bfs(grid, i , j));

                }
            }
        }
        return maxres;
    }
    vector<vector<int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>>q;
        grid[r][c] = 0;
        q.push({r,c});
        int res = 1;
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            for(int i = 0; i<4; i++) {
            int nr = node.first + directions[i][0];
            int nc = node.second + directions[i][1];

            if(nr>=0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                res++;
                q.push({nr, nc});
                grid[nr][nc] = 0;
            }

            }
        }
        return res;
    }
};