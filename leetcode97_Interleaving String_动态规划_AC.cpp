class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int size1 = s1.length();
        int size2 = s2.length();
        int size3 = s3.length();
        if(size1 + size2 != size3)
            return false;
        int dp[size1+1][size2+1] = {0};
        for( int i = 0 ; i <= size1 ; i ++ )
            for( int j = 0 ; j <= size2 ; j ++ )
            {
                if( i == 0 && j == 0 )
                    dp[i][j] = 1;
                else if( i > 0 && dp[i-1][j] && s3[i+j-1] == s1[i-1])
                    dp[i][j] = 1;
                else if( j > 0 && dp[i][j-1] && s3[i+j-1] == s2[j-1])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        return dp[size1][size2];
    }
};