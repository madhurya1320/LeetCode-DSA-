class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;                 // passed by value into helper
        helper(nums, 0, arr, res);
        return res;
    }

    void helper(vector<int>& nums, int ind, vector<int> arr, vector<vector<int>>& res) {
        if (ind == nums.size()) {
            res.push_back(arr);
            return;
        }

        // 1) Exclude nums[ind] (arr is unchanged)
        helper(nums, ind + 1, arr, res);

        // 2) Include nums[ind] (arr is a copy here)
        arr.push_back(nums[ind]);
        helper(nums, ind + 1, arr, res);
    }
};
