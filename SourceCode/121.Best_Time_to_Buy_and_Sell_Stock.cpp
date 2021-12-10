class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxmium = 0, premium = 0;
        for(int i =1; i < n; i++) {
            premium = premium + prices[i] - prices[i-1];
            if(premium < 0)  premium = 0;
            else maxmium = premium > maxmium ? premium : maxmium;
        }
        return maxmium;
    }
};