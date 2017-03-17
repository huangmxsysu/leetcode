class Solution {
public:
    double myPow(double x, int n) {
        long num = abs(long(n));
        double ans = 1;
        while( num > 0 ){
            if( num & 1 ) ans *= x;
            num >>= 1;
            x *= x;
        }
        return n>0?ans:1/ans;
    }
};