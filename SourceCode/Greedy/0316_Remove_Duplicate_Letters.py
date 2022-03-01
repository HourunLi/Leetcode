from collections import defaultdict


class Solution(object):
    def removeDuplicateLetters(self, s):
        dic = defaultdict(int)
        for ch in s:
            dic[ch] += 1

        sta = []
        for ch in s:
            if ch not in sta:
                while sta and ch <= sta[-1] and dic[sta[-1]]:
                    dic[sta[-1]] -= 1
                    sta.pop()
                sta.append(ch)
            dic[ch] -= 1
        return "".join(sta)
