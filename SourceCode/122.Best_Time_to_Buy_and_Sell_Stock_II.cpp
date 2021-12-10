class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int premium = 0;
        int n = prices.size();
        for(int i = 0; i < n-1; i++) {
            premium += prices[i+1] > prices[i] ? (prices[i+1] - prices[i]) : 0;
        }
        return premium;
    }
};


class Solution {
public:
    int max(int a, int b) {
        return a < b ? b : a;
    }
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0], sell = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            buy = max(sell-prices[i], buy);
            sell = max(buy + prices[i], sell);
        }
        return max(0, sell);
    }
};


