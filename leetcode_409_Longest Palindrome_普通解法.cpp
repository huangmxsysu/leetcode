class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> chr(123,0);
        for(int i=0;i<s.size();i++){
            chr[s[i]]++;
        }
        int max_length=0;
        int count = 0;
        int flag = 0;
        for(int i = 65 ;i<123 ;i++){
            if(chr[i] == 0) continue;
            if(chr[i] == 1) count ++;
            else{
                if(chr[i]%2 == 0) max_length += chr[i];
                else{
                    flag = 1;
                    max_length += (chr[i]-1);
                } 
            }
        }
        if(count > 0 || flag == 1) max_length ++;
        
        return max_length;
    }
};