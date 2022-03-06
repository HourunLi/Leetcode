class Solution(object):
    def dailyTemperatures(self, temperatures):
        stack = []
        ret = [0] * len(temperatures)
        for i in range(0, len(temperatures)):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                top = stack.pop()
                ret[top] = i - top
            stack.append(i)
        return ret