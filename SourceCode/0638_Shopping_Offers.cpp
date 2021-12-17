#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX/2
typedef int* intPtr;

/*solution1*/
class Solution {
private:
    intPtr dp, needsArray;
public:
    int transform(int* needsArray, int n) {
        int sum = 0;
        for(auto i = 0; i < n; i++) {
            sum = sum * 11 + needsArray[i];
        }
        return sum;
    }
    int dfs(vector<int>& price, vector<vector<int>>& special, int* needsArray, int n) {
        int trans = transform(needsArray, n);
        if(dp[trans] < INF) return dp[trans];

        for(auto &t : special) {
            bool flag = true;
            int tmp[10];
            for(int i = 0; i < n; i++) {
                tmp[i] = needsArray[i]-t[i];
                if(tmp[i] < 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                dp[trans] = min(dfs(price, special, tmp, n) + t[n], dp[trans]);
            }
        }
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += needsArray[i]*price[i];
        }
        dp[trans] = min(total, dp[trans]);
        return dp[trans];
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        int size = 1;
        for(int i = 0; i < n; i++) {
            size *= 11;
        }
        dp = (int*)malloc(size*sizeof(int));
        needsArray = (int*)malloc(n*sizeof(int));
        for(int i = 0; i < n; i++) {
            needsArray[i] = needs[i];
        }
        for(int i = 1; i < size; i++) 
            dp[i] = INF;
        dp[0] = 0;
        return dfs(price, special, needsArray, n);
    }
};

/*solution2*/
class Solution {
public:
    //使用备忘录比数组效率更高
    map<vector<int>, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();

        //过滤不需要计算的大礼包，只保留需要计算的大礼包
        vector<vector<int>> filterSpecial;
        for (auto & sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, special, needs, special, n);
    }

    // 记忆化搜索计算满足购物清单所需花费的最低价格
    int dfs(vector<int> price,const vector<vector<int>> & special, vector<int> curNeeds, vector<vector<int>> & filterSpecial, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; ++i) {
                minPrice += curNeeds[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
            }
            for (auto & curSpecial : filterSpecial) {
                bool flag = true;
                int specialPrice = curSpecial[n];
                vector<int> nxtNeeds(n);
                for (int i = 0; i < n; ++i) {
                    nxtNeeds[i] = curNeeds[i] - curSpecial[i];
                    if(nxtNeeds[i] < 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) { // 大礼包可以购买
                    minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpecial, n) + specialPrice);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};
