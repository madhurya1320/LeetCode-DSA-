class Solution {
public:
    int subsetXORSum(vector<int>&nums) {
        return subsethelper(0, nums, 0);
        
    }
    int subsethelper(int ind, vector<int>&nums, int curxor) {
        if(ind == nums.size() ) {
            return curxor;
        }
       int pick =  subsethelper(ind+1, nums, curxor ^ nums[ind]);
       int not_pick = subsethelper(ind+1, nums, curxor);

       return pick + not_pick;
    }
};