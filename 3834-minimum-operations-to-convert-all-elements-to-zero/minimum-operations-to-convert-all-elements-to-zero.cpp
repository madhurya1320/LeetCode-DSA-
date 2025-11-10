class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int>ans;
        int res = 0; 
        for(int i = 0; i<nums.size(); i++) {
            while(!ans.empty() && ans.back() > nums[i]) {
                ans.pop_back();
            }
            if(nums[i] == 0) continue;
            if(ans.empty() || ans.back()<nums[i]) {
                res++;
                ans.push_back(nums[i]);
            }
        }
        return res;
    }
};