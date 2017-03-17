class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        vector<int> count(26,0);
        int begin = 0, maxlen = 0, ans = 0;
        for(int end=0;end<size;end++){
        	maxlen = max(maxlen,++count[s[end]-'A']);
        	while(end - begin + 1 - maxlen > k) count[s[begin++] - 'A']--;//相当于count[s[begin] - 'A']--;  begin ++;
        	ans = max(ans,	end - begin + 1);
        }
        return ans;
    }
};