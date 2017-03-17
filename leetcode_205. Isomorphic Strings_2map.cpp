class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	unordered_map<char,char> my_map_s,my_map_t;
    	string temp_s = "",temp_t = "";
    	for( int i = 0 ; i < s.size() ; i ++ ){
    	    my_map_s[s[i]] = t[i];
    	    my_map_t[t[i]] = s[i];
    	}
    	for( int i = 0 ; i < s.size() ; i ++ ){
    	    temp_s += my_map_t[my_map_s[s[i]]];
    	    temp_t += my_map_s[s[i]];
    	}
    	return temp_s == s && temp_t == t?true:false;
        
    }
};