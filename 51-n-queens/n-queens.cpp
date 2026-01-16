class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

        vector<vector<char>>board(n, vector<char>(n, '.'));

        solve(0, board, ans, n);
        return ans;
    }

    void solve(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            vector<string>temp;

            for(int j = 0; j<n; j++) {
                string row(board[j].begin(), board[j].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(issafe(row, col, board, n)) {
                board[row][col] = 'Q';

                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            } 
        }
    }

    bool issafe(int row, int col,vector<vector<char>> &board, int n ) {
        for(int left = 0; left < col; left++) {
            if(board[row][left] == 'Q') return false;
        }

        for(int i = row, j = col; i>=0 && j>=0; i--,j--) {
            if(board[i][j] == 'Q') return false;
        }

        for(int i = row, j= col; i<n && j>=0; i++, j--) {
            if(board[i][j]=='Q') return false;
        
        } 

        return true;
    }
};