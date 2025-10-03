class Solution {
    vector<vector<int>>directions = {{1,0}, {-1, 0} ,{0, 1} ,{0, -1}};
public:
    //vector<vector<int>>directions = {{1,0}, {-1, 0} ,{0, 1} ,{0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(); int col = grid[0].size();
        int count = 0;
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r<0 || c<0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        for(int i = 0; i<directions.size(); i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }

    }
};