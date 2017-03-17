class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int currPrice : prices){
            if (currPrice < minPrice) minPrice = currPrice;
            else maxProfit = max(currPrice - minPrice, maxProfit);
        }
        
        return maxProfit;
    }
};