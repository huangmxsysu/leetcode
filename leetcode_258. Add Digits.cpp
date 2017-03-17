class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        int temp = 0;
        while(s.size() > 1){
            for(char c:s){
                temp += (c-48);
            }
            s.clear();
            s = to_string(temp);
            temp = 0;
        }
        return s[0]-48;
        
    }
};