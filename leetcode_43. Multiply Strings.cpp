class Solution {
public:
    string multiply(string num1, string num2) {
    	int size1 = num1.size();
    	int size2 = num2.size();
    	vector<int> ans(size1+size2,0);
    	reverse(num1.begin(),num1.end());
    	reverse(num2.begin(),num2.end());
    	for(int i=0;i<size1;i++){
    		for(int j=0;j<size2;j++){
    			ans[i+j] += (num1[i]-'0')*(num2[j]-'0');
    			ans[i+j+1] += ans[i+j]/10;
    			ans[i+j] = ans[i+j]%10;
    		}
    	}
    	int g;
    	string answer="";
    	for(g = size1+size2-1;g>0&&ans[g] == 0;g--);
    	for(;g>=0;g--){
    		answer+=(ans[g]+'0');
    	}
    	return answer; 
        
    }
};