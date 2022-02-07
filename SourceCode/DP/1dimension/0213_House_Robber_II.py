class Solution:
    def rob(self, nums):
      def rob_(nums):
        if len(nums) == 1:
            return nums[0]
        a, b = nums[0], max(nums[0:2])
        for i in range(2, len(nums)):
            c = max(b, a+nums[i])
            a, b = b, c
        return b
      return max(rob_(nums[0:-1]), rob_(nums[1:])) if len(nums) > 1 else nums[0]
