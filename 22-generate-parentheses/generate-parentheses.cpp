class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string ans = "";
        int open; int close;
        helper(0, 0, n, res, ans);
        return res;
    }

    void helper(int open, int close, int n, vector<string>&res, string& ans) {
        if(open == n && close == n) {
            res.push_back(ans);
            return;
        }

        if(open < n) {
            ans = ans + "(";
            helper(open+1, close, n, res, ans);
            ans.pop_back();
        }
         if(close < open) {
            ans = ans + ")";
            helper(open, close+1, n, res, ans);
            ans.pop_back();
        }
    }
};