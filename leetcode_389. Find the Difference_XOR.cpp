class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for( c:s ) ans ^= c;
        for( x:t ) ans ^= x;
        return ans;
    }
};