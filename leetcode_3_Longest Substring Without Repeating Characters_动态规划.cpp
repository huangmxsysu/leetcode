class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size()==1) return 1;
        vector<int> chr(256,-1);
        vector<int> dp(s.size(),-1);
        dp[0] = 0;
        chr[s[0]] = 0;
        int max = -10000;
        for(int i=1;i<s.size();i++){
            if(chr[s[i]] == -1){
                dp[i] = dp[i-1];
                chr[s[i]] = i;
            }
            else{
                if(chr[s[i]] < dp[i-1]){
                    chr[s[i]] = i;
                    dp[i] = dp[i-1];
                }
                else{
                    dp[i] = chr[s[i]]+1;
                    chr[s[i]] = i;
                }
            }
            if(i - dp[i]>max)   max = i - dp[i];
        }
        return max + 1;
    }
};