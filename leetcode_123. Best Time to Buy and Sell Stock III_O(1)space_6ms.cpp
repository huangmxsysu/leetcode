class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if( size <= 1 ) return 0;
        int sel_1 = 0 , sel_2 = 0;
        int buy_1 = -prices[0], buy_2 = -prices[0];
        int profit = 0 ;
        for( int i = 0 ; i < size ; i ++ ) {
            int last_sel = sel_1;
            sel_1 = max( sel_1 , prices[i] + buy_1 );
            buy_1 = max( -prices[i] , buy_1 );
            sel_2 = max( sel_2 , prices[i] + buy_2 );
            buy_2 = max( last_sel - prices[i] , buy_2 );
            profit = max( sel_1 , sel_2 );
        }
        return profit;
        
    }
};