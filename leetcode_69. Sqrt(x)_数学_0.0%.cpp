class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1 ) return x;
        int e = 1;
        while( x >= 0 ){
            x -= e;
            e += 2;
        }
        if( x == 0 ) return e/2;
        else return e/2 - 1;
    }
    
};