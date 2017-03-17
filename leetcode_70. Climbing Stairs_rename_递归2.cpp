int climbStairs(int n) {
        if(n == 0)  return 1;
        if(n == 1 || n == 2)    return n;
        
        int a = climbStairs(n / 2); 
        int b = climbStairs((n - 1) / 2 - 1); 
        int c = climbStairs(n / 2 - 1);
        int d = climbStairs((n -1) / 2);
        
        return b * a + d * a + d * c;
    }