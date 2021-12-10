class Solution {
public:
    int max(int a, int b) {
        return a < b ? b : a;
    }
    int maxProfit(int k, vector<int>& prices) {
        int *sell = int[k+1];
        int *buy = int[k+1];
        memset(sell, 0, (k+1)*sizeof(int));
        memset(buy, 0, (k+1)*sizeof(int));
        for(int i =1; i <= k; i++) 
            buy[i] = -prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                buy[j] = max(sell[j-1]-price[i], buy[j]);
                sell[j] = max(buy[j-1] + price[i], sell[j]);
            }
        }
        return *max_element(sell, sell + k + 1);
    }
};