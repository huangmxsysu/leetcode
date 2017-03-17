class Solution {
public:
    
    int firstUniqChar(string s) {
        int size = s.size();
        vector<int> flag( 256 , -1 );
        for( int i = 0 ; i < size ; i++ ){
            if( flag[s[i]] == -1 ) flag[s[i]] = 1;
            else if( flag[s[i]] == 1 ){
                flag[s[i]] = 0;
            }
        }
        int i,ans = 0;
        for( i = 0 ; i < size ; i++ ){
            if( flag[s[i]] == 1 ){
                ans = 1;
                break;
            }
        }
        if(ans) return i;
        else return -1;
    }
};