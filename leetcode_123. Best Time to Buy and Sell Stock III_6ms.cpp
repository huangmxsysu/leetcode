class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if( size <= 1 ) return 0;
        int profit[size];
        memset(profit,0,sizeof(profit));
        int max_profit = 0;
        int Mins = prices[0];
        for( int i = 1 ; i < size ; i ++ ){
            if( prices[i] - Mins > max_profit ) max_profit = prices[i] - Mins;
            if( prices[i] < Mins ) Mins = prices[i];
            profit[i] = max_profit;
        }
        int max_profit_r = 0;
        int Maxs = prices[size - 1] ;
        for( int i = size - 1 ; i >= 0 ; i-- ){
            if( profit[i] + Maxs - prices[i] > max_profit_r ) max_profit_r = profit[i] + Maxs - prices[i];
            if( Maxs < prices[i] ) Maxs = prices[i];
        }
        return max_profit_r;
        
    }
};