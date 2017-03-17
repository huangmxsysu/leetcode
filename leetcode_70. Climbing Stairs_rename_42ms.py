class Solution(object):
    def climbStairs(self, n):
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            a = 1
            b = 2
            for x in range(2, n):
                if x%2 == 0:
                    a = a+b
                else:
                    b = a+b
            if x%2 == 0:
                return a
            else:
                return b