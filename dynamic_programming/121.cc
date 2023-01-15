class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dup(prices.size());
        dup[0] = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dup[i] = min(dup[i-1], prices[i]);
        }
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - dup[i] > ret) {
                ret = prices[i] - dup[i];
            } 
        }
        return ret;
    }
};
