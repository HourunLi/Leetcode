from collections import defaultdict
"""
class Solution:
    def findRepeatedDnaSequences(self, s):
        ans = []
        cnt = defaultdict(int)
        for i in range(len(s) - 9):
            sub = s[i: i + 10]
            cnt[sub] += 1
            if cnt[sub] == 2:
                ans.append(sub)
        return ans
"""

bin = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
class Solution:
    def findRepeatedDnaSequences(self, s):
        n = len(s)
        if n <= 10:
            return []
        ans = []
        x = 0
        for ch in s[:9]:
            x = (x << 2) | bin[ch]
        cnt = defaultdict(int)
        for i in range(n - 9):
            x = ((x << 2) | bin[s[i + 9]]) & ((1 << 20) - 1)
            cnt[x] += 1
            if cnt[x] == 2:
                ans.append(s[i: i + 10])
        return ans
