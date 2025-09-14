class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0; int r = people.size()-1; int boat = 0;
        while(l<=r) {
            if(people[l] + people[r] <= limit) {
                l++;
            }
                r--;
                boat++;
        }
        return boat;
    }
};