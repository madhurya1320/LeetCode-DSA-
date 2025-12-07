class Solution {
public:

    int r, c;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int ro, int co, vector<vector<bool>>& visited,
             vector<vector<int>>& heights) {

        visited[ro][co] = true;

        for (auto &d : directions) {
            int nr = ro + d[0];
            int nc = co + d[1];

            if (nr >= 0 && nc >= 0 && nr < r && nc < c &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[ro][co]) {

                dfs(nr, nc, visited, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        r = heights.size();
        c = heights[0].size();

        vector<vector<bool>> pac(r, vector<bool>(c, false));
        vector<vector<bool>> atl(r, vector<bool>(c, false));

        for (int i = 0; i < c; i++) dfs(0, i, pac, heights);
        for (int i = 0; i < r; i++) dfs(i, 0, pac, heights);

       
        for (int i = 0; i < c; i++) dfs(r - 1, i, atl, heights);
        for (int i = 0; i < r; i++) dfs(i, c - 1, atl, heights);

        vector<vector<int>> res;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
