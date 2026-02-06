class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int rows, cols;

    void dfs(vector<vector<int>>& grid, int r, int c, int &perim) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
            perim++;     // boundary edge
            return;
        }
        if (grid[r][c] == 2) return; // visited

        grid[r][c] = 2;

        for (int k = 0; k < 4; k++) {
            dfs(grid, r + dirs[k][0], c + dirs[k][1], perim);
        }
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int perim = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    dfs(grid, r, c, perim);
                    return perim;
                }
            }
        }
        return 0;
    }
};
