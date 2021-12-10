class Solution {
public:
    int max(int a, int b) {
        return a < b ? b : a;
    }
    int max(int a, int b, int c) {
        return max(c, max(a,b));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //sell1, sell2 within cooldown, sell3 not
        int sell1 = 0, sell2 = 0, sell3 = 0, buy = -prices[0];

        for(int i = 1; i < n; i++) {
            sell3 = max(sell3, sell2);
            sell2 = sell1;
            sell1 = buy + prices[i];
            buy = max(buy, sell3 - prices[i]);
        }
        return max(sell1, sell2, sell3);
    }
};