class Solution {
public:
	int min(priority_queue<int> p){
		return p.top();
	}
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	if(n == 1) return 1;
    	priority_queue<int> p,p1;
    	for(int i=0;i<primes.size();i++){
    		p.push_back(primes[i]);
    		p_temp.push_back(primes[i]);
    	}
    	int val[primes.size()];
    	int val_base[primes.size()];
    	int count = 0,count1 = 0;
    	while(p1.size()){
    		val[count++]=p1.top();
    		val_base[count1++] = p1.top();
    		p1.pop();
    	}
    	int index[primes.size()]={0};
    	for(int i = 1;i < n; i++){
    		temp = p.top();
    		p.pop();
    		ugly_list[i] = temp;
    		for(int j = 0;j < primes.size();j++){
    			if(temp == val[i]){
    				val[i] = ugly_list[++index[i]]*val_base[i];
    				p.push_back(val[i]);
    			}
    		}
    	}
    	return ugly_list[n-1];

        
    }
};