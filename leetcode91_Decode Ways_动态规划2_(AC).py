class Solution(object):
    def numDecodings(self, s):
        if (len(s) == 0 or s[0] == '0'):
            return 0
        p1 = 1
        p2 = 1
        for i in range(1,len(s)):
            if s[i] == '0':
                p1 = 0
            if s[i-1] == '1' or (s[i-1] == '2' and s[i] <= '6'):
                p1 = p1 + p2
                p2 = p1 - p2
            else:
                p2 = p1
        return p1