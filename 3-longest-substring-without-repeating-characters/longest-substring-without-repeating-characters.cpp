class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int>mp;
        int l = 0; int len = 0;
        for(int r = 0; r < s.size(); r++) {
            if(mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]]+1, l);
            }
            mp[s[r]] = r;
            len = max(len, r-l+1);
        }
        return len;
     }
};