class Solution {
public:
vector<string> res;
vector<string> digiTo = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i, string cur, string &digits) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }
        string chars = digiTo[digits[i] - '0'];
        for (char c : chars) {
            backtrack(i + 1, cur + c, digits);
        }
    }
};