class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int l = 0; int r = 0; int count = 0; int min = INT_MAX; int start_index = -1;
        for(int i = 0; i<t.size(); i++) {
            mp[t[i]]++;
        }

        for(int r = 0; r < s.size(); r++) {
            if(mp[s[r]] > 0) {
                count++;
            }
            mp[s[r]]--;

    while(count == t.size()) {
        if(r-l+1 < min) {
            min = r-l+1;
            start_index = l;
            
        }
        mp[s[l]]++;
        if(mp[s[l]] > 0) {
            count--;
        }
        l++;
    }
}
    if(start_index == -1) {
        return "";
    } else {
        return s.substr(start_index, min);
    }
    }
};