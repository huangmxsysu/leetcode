class Solution {
public:
    char findTheDifference(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        int f;
        char ans=t[0];
        vector<int> flag( size1 , 0 );
        for( int i = 0 ; i < size2 ; i ++ )
        {
            f = 0;
            for( int j = 0 ; j < size1 ; j ++ ){
                if( flag[j] == 1 ) continue;
                if( s[j] == t[i] ){
                    flag[j] = 1;
                    f = 1;
                    break;
                }
            }
            if( f == 0 ){
                ans = t[i];
                break;
            };
        }
        return ans;
    }
};