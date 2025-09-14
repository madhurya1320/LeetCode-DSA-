class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, cur = 0;
        unordered_map<int, int> pSums;
        pSums[0] = 1;

        for (int num : nums) {
            cur += num;
            int diff = cur - k;
            res = res +  pSums[diff];
            pSums[cur]++;
        }

        return res;
    }
};