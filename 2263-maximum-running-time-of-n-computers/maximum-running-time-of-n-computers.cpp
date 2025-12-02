class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0;
        long long r = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        long long ans = 0;

        while (l <= r) {
            long long mid = r - (r - l) / 2;   

            long long total = 0;
            for (long long b : batteries) {
                total += min(b, mid);
            }

            if (total >= mid * n) {     
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
