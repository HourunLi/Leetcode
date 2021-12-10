class Solution {
public:
    int max(int a, int b) {
        return a < b ? b : a;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(!n) return 0;
        int buy = -prices[0]-fee, sell = 0;
        for(int i =1; i < n; i++) {
            sell = max(buy + prices[i], sell);
            buy = max(sell - prices[i] -fee, buy);
        }
        return max(sell, 0);
    }
};