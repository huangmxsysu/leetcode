class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if ( size == 0 || size == 1 ) return 0;
        int high = prices[size - 1] , max_profit = 0;
        for ( int i = size - 2 ; i >= 0 ; i -- ){
            if ( prices[i] > prices[i+1] ){
                max_profit += high - prices[i+1];
                high = prices[i];
            }
        }
        if ( prices[0] < high ) max_profit += high - prices[0];
        return max_profit;
    }
};