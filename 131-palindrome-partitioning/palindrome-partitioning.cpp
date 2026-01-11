class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ans;
        helper(0, s, ans, res);
        return res;
    }

    void helper(int i, string s, vector<string>&ans, vector<vector<string>>&res) {
        if(i == s.size()) {
            res.push_back(ans);
            return;
        }

        for(int j = i; j<s.size(); j++) {
            if(ispalindrome(s, i, j)) {
                ans.push_back(s.substr(i, j-i+1));
                helper(j+1, s, ans, res);
                ans.pop_back();
            }
        }

        
    }

    bool ispalindrome(string s, int i, int j) {
            while(i<=j) {
            if(s[i]!=s[j]) {
                return false;
            }
                i++;
                j--;
            }
            return true;
        }
};