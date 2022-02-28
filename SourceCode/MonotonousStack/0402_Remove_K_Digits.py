class Solution:
    def removeKdigits(self, num, k):
        n = len(num)
        if n <= k:
            return "0"
        sta = []
        for i in range(n):
            while(sta and num[i] <= sta[-1] and k):
                sta.pop()
                k -= 1
            sta.append(num[i])
        while k:
            sta.pop()
            k -= 1
        while sta and sta[0] == '0':
            sta.pop(0)
        return "".join(sta) if sta else "0"
