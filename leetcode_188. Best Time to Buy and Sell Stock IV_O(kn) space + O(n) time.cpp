class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if (prices.size() <= 1) return 0;
        if ( k > prices.size()/2 ){
            int max_profit = 0;
            for( int i = 1 ; i < prices.size() ; i ++ ){
                max_profit += max( prices[i] - prices[i-1] , 0 );
            }
            return max_profit;
        }
        else {
            
            int maxProf = 0;
            vector<vector<int>> f(k+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= k; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
    }
};