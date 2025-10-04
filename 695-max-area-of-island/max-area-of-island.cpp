class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(); int c = grid[0].size(); int maxcount = 0; 
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    maxcount = max(maxcount,count);
                }
            }
        }
        return maxcount;
    }
    vector<vector<int>>directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& grid, int row, int col, int& count) {
        if(row < 0 || col <0 || row>=grid.size() || col >=grid[0].size() || grid[row][col] == 0) return;

        grid[row][col] = 0;
        count = count + 1; 

    for(int i = 0; i<4; i++) {
        int nr = row + directions[i][0];
        int nc = col + directions[i][1];
            dfs(grid, nr, nc, count);
        
    }
    }
};