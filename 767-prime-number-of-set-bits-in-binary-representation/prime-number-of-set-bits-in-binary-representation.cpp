class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;

    for (int i = left; i <= right; i++) {
        int count = 0;
        int n = i;

        while (n != 0) {
            if (n % 2 == 1)
                count++;

            n = n / 2;
        }

        if (isPrime(count))
            res++;
    }

    return res;
    }
    bool isPrime(int n) {
    return (n == 2 || n == 3 || n == 5 || n == 7 ||
            n == 11 || n == 13 || n == 17 || n == 19);
}
};