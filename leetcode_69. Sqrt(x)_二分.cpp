class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1 ) return x;
        int mid,low=0,high=x;
        while(low < high ){
            mid = ( low + high )/2;
            if( x/mid >= mid ) low = mid + 1;
            else high = mid;
        }
        return high-1;
    }
    
};