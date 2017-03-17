class Solution {
public:
    string longestPalindrome(string s) {
        int count = 1;
        int max = -10000;
        int index = 0;
        int size = s.size();
        int flag = 0;
        for(int i=0;i<size;i++){
            if(s[i]==s[i-1]){
                while(i-1-count>=0 && i+count<size && s[i-1-count] == s[i+count])   count++;
                if(count*2>max){
                    index = i;
                    max = count*2;
                    flag = 1;
                }
            }
            count = 1;
            while(i-count>=0 && i+count<size && s[i-count] == s[i+count])   count++;
            if(count*2 - 1 > max){
                index = i;
                max = count*2-1;
                flag = 0;
            }
            count = 1;
        }
        string ans;
        if(flag == 0){
            for(int i = index-(max-1)/2;i<=index + (max-1)/2;i++) ans += s[i];
        }
        else{
            for(int i = index - max/2;i<=index + max/2 -1;i++) ans += s[i];
        }
        return ans;
    }
};