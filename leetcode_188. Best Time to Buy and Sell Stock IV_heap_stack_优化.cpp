class Solution 
{
public:
    // We can find all adjacent valley/peak pairs and calculate the profits easily. 
    // Instead of accumulating all these profits like Buy&Sell Stock II, we need 
    // the highest k ones.
    // 
    // The key point is when there are two v/p pairs (v1, p1) and (v2, p2), satisfying 
    // v1 <= v2 and p1 <= p2, we can either make one transaction at [v1, p2], or make 
    // two at both [v1, p1] and [v2, p2]. The trick is to treat [v1, p2] as the first 
    // transaction, and [v2, p1] as the second. Then we can guarantee the right max 
    // profits in both situations, p2 - v1 for one transaction and p1 - v1 + p2 - v2 
    // for two.
    // 
    // Finding all v/p pairs and calculating the profits takes O(n) since there are 
    // up to n/2 such pairs. And extracting k maximums from the heap consumes another O(k*log(n)).
    int maxProfit(int k, vector<int> &prices) 
    {
        int ret = 0;
        int n = prices.size(); 
        int v = 0;  // valley index 
        int p = 0;  // peak index + 1;
        
        vector<int> profits;
        stack<pair<int, int>> vp_pairs;
        while (p < n) 
        {
            // Find next valley/peak pair.
            for (v = p; (v < n - 1) && (prices[v] >= prices[v + 1]); v++);
            for (p = v + 1; (p < n) && (prices[p] >= prices[p - 1]); p++);
            
            // Save profit of 1 transaction at last v/p pair, if current v is lower than last v.
            while (!vp_pairs.empty() && (prices[v] < prices[vp_pairs.top().first]))
            {
                profits.push_back(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }
            
            // Save profit difference between 1 transaction (last v and current p) and 2 transactions 
            // (last v/p + current v/p), if current v is higher than last v and current p is higher 
            // than last p.
            while (!vp_pairs.empty() && (prices[p - 1] >= prices[vp_pairs.top().second - 1])) 
            {
                profits.push_back(prices[vp_pairs.top().second - 1] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            
            vp_pairs.push(pair<int, int>(v, p));
        }
        
        // Save profits of the remaining v/p pairs.
        while (!vp_pairs.empty()) 
        {
            profits.push_back(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        
        if (k >= profits.size())
        {
            // Since we have no more than k profit pairs, the result is the sum of all pairs.
            ret = accumulate(profits.begin(), profits.end(), 0);
        }
        else
        {
            // Move the k highest profits to the end and the average time complexity should be O(n).
            nth_element(profits.begin(), profits.begin() + profits.size() - k, profits.end());
            // Sum up the k highest profits.
            ret = accumulate(profits.begin() + profits.size() - k, profits.end(), 0);
        }
        
        return ret;
    }
};