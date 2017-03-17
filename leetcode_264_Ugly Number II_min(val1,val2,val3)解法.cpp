class Solution {
public:
    int min(int val1,int val2,int val3){
        int temp = val1>val2?val2:val1;
        return temp>val3?val3:temp;
    }
    int nthUglyNumber(int n){
        if(n==1) return 1;
        int *ugly_list = new int[n];
        int val1 = 2,val2 = 3,val3 = 5;
        int index1 = 0;
        int index2 = 0;
        int index3 = 0;
        int temp = 0;
        for(int i=1;i<n;i++){
            temp = min(val1,val2,val3);
            ugly_list[i] = temp;
            if(temp == val1) val1 = ugly_list[++index1] * 2;
            if(temp == val2) val2 = ugly_list[++index2] * 3;
            if(temp == val3) val3 = ugly_list[++index3] * 5;
        }
        return ugly_list[n-1];

    }
};