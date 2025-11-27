class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;
        for(int i = 0; i<s.size(); i++) {
            mp[s[i]] = i;
        }
        int c = 0; int end = 0;
        vector<int>res;
        for(int i = 0; i<s.size(); i++) {
            c++;
            end = max(end, mp[s[i]]);

            if(i == end){
            res.push_back(c);
            c = 0;
            }
        }
        return res;
    }
};
