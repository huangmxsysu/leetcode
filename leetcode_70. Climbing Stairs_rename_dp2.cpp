int climbStairs(int n) {
    if(n==0||n==1) return  1;
    int One=1,Two=1;
    int result=0;
    for(int i=2;i<=n;i++){
        result=One+Two;
        Two=One;
        One=result;
    }
    return result;
}