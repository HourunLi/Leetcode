
class Solution {
public:
    int max(int i, int j) {
        return (i > j) ? i : j;
    }
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for(int i = 1; i < n; i++) {
            buy1 = max(-prices[i], buy1);
            sell1 = max(buy1 + prices[i], sell1);
            buy2 = max(sell1-prices[i], buy2);
            sell2 = max(buy2+prices[i],sell2);
        }
        return max(0,max(sell1, sell2));
    }
};