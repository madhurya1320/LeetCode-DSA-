class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>arr;
        helper(s, res, arr, 0);
        return res;
    }

    void helper(string s,vector<vector<string>>&res,vector<string>&arr, int i ) {
        if(i == s.size()) {
            res.push_back(arr);
            return;
        }
        for(int j = i; j<s.size(); j++) {
            if(ispalin(s, i, j)) {
                arr.push_back(s.substr(i, j-i+1));
                helper(s, res, arr, j+1);
                arr.pop_back();
            }
        }
    }

    bool ispalin(string s, int i, int j) {
        while(i<=j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};