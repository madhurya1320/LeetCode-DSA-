class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;

        for(int n : s) {
            if(s.find(n-1) == s.end()) {
                int len = 1;

                while(s.find(n + len)!=s.end()) {
                    len++;
                }
            longest = max(longest, len);
            }
            
            
        }
        return longest;
    }
};