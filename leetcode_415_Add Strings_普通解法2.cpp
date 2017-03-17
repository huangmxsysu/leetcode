class Solution {
public:
    string addStrings(string num1, string num2) {
    	int size1 = num1.length(),size2 = num2.length(),carry = 0;
    	size1--;
    	size2--;
    	string ans = "";
    	while(size1>=0||size2>=0){
    		int val1 = size1>=0?num1[size1--]-'0':0;
    		int val2 = size2>=0?num2[size2--]-'0':0;
    		int temp = val1 + val2 + carry;
    		ans.insert(ans.begin(),temp%10+'0');
    		carry = temp/10;
    	}
    	return carry?'1'+ans:ans;
    }
};