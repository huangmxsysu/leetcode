class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0)
        return 0;
        int low = prices[0];
        int high = prices[0];
        int temp_low=low;
        for(int i=1;i<size;i++)
        {
            if(prices[i]-temp_low>=high-low)
            {
                low = temp_low;
                high = prices[i];
            }
            else if(prices[i]>high)
            high = prices[i];
            else if(prices[i]<=low)
            {
                if(prices[i]<=temp_low) temp_low = prices[i];
            }
            
 
        }
        if(high-low<=0)
        return 0;
        else
        return high - low;
    }
};