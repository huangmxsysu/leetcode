class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while( x > 0 && y > 0 ){
            if( x%2 != y%2 ) ans++;
            x /= 2;
            y /= 2;
        }
        while( x > 0 ){
            if( x % 2 == 1 )
                ans++;
            x /= 2;
        }
        while( y > 0 ){
            if( y % 2 == 1 )
                 ans ++;
             y /= 2;
        }
        return ans;
    }
};