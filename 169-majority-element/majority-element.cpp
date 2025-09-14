class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0; int mj;
        for(int i = 0; i<nums.size(); i++) {
            if(count == 0) {
                mj = nums[i];
            }
            if(nums[i] != mj) {
                count--;
            } else  {
                count++;
            }
        }
        return mj;
    }
};