class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        if(num == 1) return true;
        int temp = num;
        while(temp%2==0){
            temp = temp/2;
        }
        while(temp%3==0){
            temp = temp/3;
        }
        while(temp%5==0){
            temp = temp/5;
        }
        if(temp==1) return true;
        else
        return false;

    }
};