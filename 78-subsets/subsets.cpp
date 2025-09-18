class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>arr;
        helper(0,nums, res, arr);
        return res;
    }

    void helper(int i, vector<int>&nums, vector<vector<int>>&res, vector<int>&arr) {
        if(i == nums.size()) {
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        helper(i+1, nums, res, arr);
        arr.pop_back();
        helper(i+1, nums, res, arr);
    }
};