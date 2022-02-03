class Solution(object):
    def numDecodings(self, s):
        n = len(s)
        print(n)
        a, c = 1, 0
        b = 1 if s[0] != '0' else 0
        for i in range(1, n):
            c = 0
            if s[i] != '0':
                c += b
            if s[i-1] != '0' and int(s[i-1: i+1]) <= 26:
                c += a
            a, b = b, c

        return c if n > 1 else b
