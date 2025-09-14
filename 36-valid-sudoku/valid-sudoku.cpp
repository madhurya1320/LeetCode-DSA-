class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>>rows, cols;
        map<pair<int, int>, unordered_set<char>>sk;

        int m = board.size(); int n = board[0].size();

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++){
                if(board[i][j] == '.') continue;

                pair<int, int>square = {i/3, j/3};

                if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || sk[square].count(board[i][j])) {
                    return false;
            }

        rows[i].insert(board[i][j]);
        cols[j].insert(board[i][j]);
        sk[square].insert(board[i][j]);
    }

    }
    return true;
    }
};