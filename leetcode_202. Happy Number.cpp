class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        int t = 6;
        int temp = 0;
        while(t--){
            for(char c:s){
                temp += (c-48)*(c-48);
            }
            if(temp == 1 || to_string(temp) == s) return true;
            s = to_string(temp);
            temp = 0;
        }
        return false;
        
    }
};