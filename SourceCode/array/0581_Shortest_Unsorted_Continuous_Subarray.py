class Solution(object):
    def findUnsortedSubarray(self, nums):
        n = len(nums)
        maxn, r = float("-inf"), -1
        minn, l = float("inf"), -1
        for i in range(n):
            if minn >= nums[n-i-1]:
                minn = nums[n-i-1]
            else:
                l = n - i - 1

            if maxn <= nums[i]:
                maxn = nums[i]
            else:
                r = i
        return 0 if r == -1 else r - l + 1
