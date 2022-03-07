class Solution(object):
    def findMaxValueOfEquation(self, points, k):
        ret = float("-inf")
        deque = []
        length = len(points)

        for r in range(1, length):
            while deque and points[r][0] - points[deque[0]][0] > k:
                deque.pop(0)

            if deque:
                tmp = points[r][1] + points[deque[0]][1] + \
                    points[r][0] - points[deque[0]][0]
                ret = tmp if tmp > ret else ret

            if points[r][0] - points[r-1][0] <= k:
                tmp = points[r][1] + points[r-1][1] + \
                    points[r][0] - points[r-1][0]
                ret = tmp if tmp > ret else ret
                while deque and tmp > points[r][1] + points[deque[-1]][1] + points[r][0] - points[deque[-1]][0]:
                    deque.pop()
                deque.append(r-1)
        return ret
