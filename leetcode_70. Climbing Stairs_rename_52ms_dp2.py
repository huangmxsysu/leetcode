class Solution(object):
    def climbStairs(self, n):
        if n < 3:
            return n
        a, b = 1, 1
        c = 0
        for i in range(n-1):
            c = a + b
            a = b
            b = c
        return c