class Solution {
public:
    int c = 0;
    int countOdds(int low, int high) {
        for(int i = low; i<=high; i++) {
            if(i%2 !=0) {
                c++;
            }
        }
        return c;
    }
};