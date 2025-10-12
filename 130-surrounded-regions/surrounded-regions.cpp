class Solution {
public:
  vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int r = board.size(); int c = board[0].size();
        
        for(int j = 0; j<c; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[r-1][j] == 'O') dfs(board, r-1, j);
        }

        for(int i = 0; i<r; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][c-1] == 'O') dfs(board, i, c-1);
        }

        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int row, int col) {
          if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
        || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '#';
        for(int i = 0; i<4; i++) {
            int nr = row + directions[i][0];
            int nc = col + directions[i][1];

            dfs(board, nr, nc);
        }


    }
};