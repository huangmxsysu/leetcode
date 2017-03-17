class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0 ) return false;
        if( n == 1 ) return true;
        if( n % 2 == 1 ) return false;
        long temp = 1;
        while( temp <= n ){
            if( temp == n ) return true;
            temp *= 2;
        }
        return false;
    }
};