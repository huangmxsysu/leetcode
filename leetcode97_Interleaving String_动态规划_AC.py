class Solution(object):
    def isInterleave(self, s1, s2, s3):
        size1 = len(s1)
        size2 = len(s2)
        size3 = len(s3)
        if size1 + size2 != size3:
            return False
        dp = [[0]*(size2 + 1) for i in range(size1 + 1)]
        for i in range(size1 + 1):
            for j in range(size2 + 1):
                if i == 0 and j == 0:
                    dp[i][j] = 1
                elif i > 0 and dp[i-1][j] and s3[i + j - 1] == s1[i - 1]:
                    dp[i][j] = 1
                elif j > 0 and dp[i][j -1] and s3[i + j - 1] == s2[j - 1]:
                    dp[i][j] = 1
                else:
                    dp[i][j] = 0
        return True if dp[size1][size2] else False