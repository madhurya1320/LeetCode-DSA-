class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        for(int i = 0; i<str[0].size(); i++) {
            char c = str[0][i];
        for(int j = 1; j<str.size(); j++) {
            if(i>str[j].size() || c != str[j][i] ) {
                return str[0].substr(0, i);
            }
        }
        }
        return str[0];
    }
};