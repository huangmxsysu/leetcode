class Solution {
public:
    bool isPowerOfFour(int num) {
        return  num > 0 && ( num & ( num - 1 ) ) == 0 && ( num - 1 ) % 3 == 0 ;
    }
};
//4的次方的某个数必然：1. 满足二进制只有1位是1其余位都是0（通过每次将1左移2位得到），2. 这个数减1以后能被3整除