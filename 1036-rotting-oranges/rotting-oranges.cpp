class Solution {
public:
    queue<pair<pair<int,int>, int>>q; int time_max = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(); int c = grid[0].size(); int fresh = 0; 
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j},0});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        vector<vector<int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()) {
            auto node = q.front().first;
            int time = q.front().second;
            q.pop();
            time_max = max(time_max, time);


            for(int i = 0; i<4; i++) {
            int nr = node.first + directions[i][0];
            int nc = node.second + directions[i][1];

               if(nr>=0 && nc >=0 && nr<grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                grid[nr][nc] = 2;
                //tmax = time + 1;
                q.push({{nr,nc},time + 1});
                fresh--;
               }
            }
        }
        
        if(fresh != 0) {
            return -1;
        } 
            return time_max;
    }
};