class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if ( size == 0 || size == 1 ) return 0;
        int low = prices[0] , max_profit = 0;
        for ( int p : prices ){
            if ( p > low ) max_profit += p - low;
            low = p;
        }
        return max_profit;
    }
};