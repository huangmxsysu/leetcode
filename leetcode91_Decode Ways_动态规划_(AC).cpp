class Solution {
public:
    int numDecodings(string s) {
    	if(s[0] == '0' || s.length() == 0) return 0;
    	int p1=1,p2=1;
    	for(int i=1;i<s.length();i++){
    		if(s[i] == '0') p1 = 0;
    		if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6'){
    			p1 = p2 + p1;
    			p2 = p1 - p2;
    		}
    		else p2 = p1;
    	}
        return p1;
    }
};