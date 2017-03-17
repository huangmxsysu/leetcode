class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans  = 0;
        int flag = x^y;
        while( flag > 0 ){
            ans += ( flag%2 ) & 1 ;
            flag = flag>>1;
        }
            
        return ans;
    }
};