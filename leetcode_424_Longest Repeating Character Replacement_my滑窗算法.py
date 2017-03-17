class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        size = len(s)
        count = [0]*26
        begin = 0
        maxlen = 0
        ans = 0
        for end in range(size):
        	count[s[end]] = count[s[end]] + 1
        	maxlen = max(maxlen,count[s[end]])
        	while end - begin + 1 - maxlen > k:
        		count[s[begin]]--
        		begin++
        	ans = max(ans,end - begin + 1)
        return ans