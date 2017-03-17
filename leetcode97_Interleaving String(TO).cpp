class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s1.length() == 0)
    		return s2 == s3;
    	if(s2.length() == 0)
    		return s1 == s3;
    	if(s3.length() == 0)
    		return s1.length() + s2.length() == 0;
    	if(s1[0] == s3[0] && s2[0] != s3[0])
    		return isInterleave(s1.substr(1),s2,s3.substr(1));
    	else if(s1[0] != s3[0] && s2[0] == s3[0])
    		return isInterleave(s1,s2.substr(1),s3.substr(1));
    	else if(s1[0] == s3[0] && s2[0] == s3[0])
    		return isInterleave(s1,s2.substr(1),s3.substr(1)) || isInterleave(s1.substr(1),s2,s3.substr(1));
    	else
    		return false;
    }
};