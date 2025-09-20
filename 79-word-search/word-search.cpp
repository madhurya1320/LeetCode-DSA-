class Solution {
public:
    int row;  int col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int i, int j, int n) {
        if(n == word.size()) {
            return true;
        }
        if(i<0 || j<0 ||i>=row || j >=col ||board[i][j] != word[n] || board[i][j] == '#' ) {
            return false;
        }
        board[i][j] = '#';
        bool res = helper(board, word, i+1, j, n+1) || helper(board, word, i-1, j, n+1) || helper(board, word, i, j+1, n+1) || helper(board, word, i, j-1, n+1);
        board[i][j] = word[n];
        return res;

    }
};