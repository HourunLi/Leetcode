# solution 1
class Solution:
    def carFleet(self, target, position, speed):
        cars = sorted(zip(position, speed))
        times = [float(target - p) / s for p, s in cars]
        stack = []
        ans = 0
        while times:
            time = times.pop()
            while stack and stack[-1] < time:
                stack.pop()
            if not stack:
                ans += 1
            stack.append(time)
        return ans


# solution2
class Solution:
    def carFleet(self, target, position, speed):
        cars = sorted(zip(position, speed))
        times = [float(target - p) / s for p, s in cars]
        stack = []
        ans = 1
        lead = times.pop()
        while times:
            time = times.pop()
            if time > lead:
                ans += 1
                lead = time
        return ans
