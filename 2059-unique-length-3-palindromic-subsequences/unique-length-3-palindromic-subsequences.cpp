class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26, -1);
        vector<int>second(26, -1);

        for(int i = 0; i<s.size(); i++) {
            int n = s[i] - 'a';
            if(first[n] == -1) {
                first[n] = i;
            }
            second[n] = i; 
        }
        int ans = 0;
        for(int i = 0; i<26; i++) {
            if(first[i] == -1) {
                continue;
            }
            unordered_set<char>st;
            for(int k = first[i]+1; k<second[i]; k++) {
                st.insert(s[k]);
            }

            ans = ans + st.size();
        }

        return ans;
    }
};