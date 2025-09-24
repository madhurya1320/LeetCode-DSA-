class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;


        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }

       
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

     
        res += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0) return res;

        res += ".";
        unordered_map<long long, int> remainderIndex;

        while (remainder != 0) {
            if (remainderIndex.count(remainder)) {
               
                res.insert(remainderIndex[remainder], "(");
                res += ")";
                break;
            }

            remainderIndex[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder / d);
            remainder %= d;
        }

        return res;
    }
};