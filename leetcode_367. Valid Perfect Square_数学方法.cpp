

class Solution {

public:
    bool isPerfectSquare(int num) {
        int e = 1;
        while(num > 0) {
            num -= e;
            e += 2;
        }
        return num == 0;
    }

};