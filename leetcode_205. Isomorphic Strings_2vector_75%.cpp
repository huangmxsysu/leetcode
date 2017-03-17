class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	vector<char> my_map_s(256,0),my_map_t(256,0);
    	for( int i = 0 ; i < s.size() ; i ++ ){
            if(my_map_s[s[i]] == 0 && my_map_t[t[i]] == 0){
                my_map_s[s[i]] = t[i];
                my_map_t[t[i]] = s[i];
            }
            else{
                if(my_map_s[s[i]] != t[i] || my_map_t[t[i]] != s[i]) return false;
            }   	    
    	} 
    }
};