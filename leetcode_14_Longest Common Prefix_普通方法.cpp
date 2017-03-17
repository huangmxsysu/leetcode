class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int count = 0;
        int flag = 1;
        string ans = "";
        while(flag){
            char temp = strs[0][count];
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i][count]=='\0' || strs[i][count] != temp)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                ans += strs[0][count];
                count++;
            }
            
        }
        return ans;
        
    }
};