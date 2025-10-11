class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(); int c = grid[0].size(); int count = 0;
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
    void dfs(vector<vector<char>>& grid, int ro, int cl) {
        if(ro < 0 || cl < 0 || ro >= grid.size() || cl >=grid[0].size() || grid[ro][cl] == '0' ) {
            return;
        }
        grid[ro][cl] = '0';
        for(int i = 0; i<4; i++) {
            //int nr = ro + directions[i][0];
            //int nc = cl + directions[i][1];

            dfs(grid, ro + directions[i][0], cl + directions[i][1]);
        }
    }
};