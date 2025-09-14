class Solution {
public:
    int maxArea(vector<int>& a) {
      int l = 0; int r = a.size() - 1;
      int res = 0;
      while(l<r) {
        int area = min(a[l], a[r]) * (r-l);
        res = max(area, res);

        if(a[l] < a[r]) {
            l++;
        } else {
            r--;
        }
      }
      return res;
    }
};