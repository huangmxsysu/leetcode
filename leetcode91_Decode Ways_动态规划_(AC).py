class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) is 0:
        	return 0
        dp = [1] + [0]*len(s)
        for i in range(1,len(s)+1):
        	dp[i] = 0 if s[i-1]=='0' else dp[i-1]
        	dp[i] += dp[i-2] if (i>1 and (s[i-2]=='1' or (s[i-2] == '2' and s[i-1] <= '6'))) else 0
        return dp[len(s)]