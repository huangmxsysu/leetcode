class Solution {
public:
  int maxProfit(vector<int>& prices) {
      int Nsize = prices.size();
      int sumCurrent = 0;
      int sumIncrease = 0;
      
          for(int i = 1; i < Nsize; i++)
          {
              sumIncrease = sumIncrease + prices[i] - prices[i-1];
             if(sumIncrease > sumCurrent) sumCurrent = sumIncrease;
             if(sumIncrease < 0) sumIncrease = 0; 
      
          }
        return sumCurrent;   
    }
};