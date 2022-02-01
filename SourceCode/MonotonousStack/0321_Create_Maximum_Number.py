class Solution:
    def maxNumber(self, nums1, nums2, k):
        m, n = len(nums1), len(nums2)
        start, end = max(0, k - n), min(k, m)

        return max(self.merge(self.getMaxSubsequence(nums1, i), self.getMaxSubsequence(nums2, k - i)) for i in range(start, end+1))

    def getMaxSubsequence(self, nums, k):
        stack = []
        remain = len(nums) - k

        for num in nums:
            while stack and stack[-1] < num and remain > 0:
                remain -= 1
                stack.pop()
            stack.append(num)

        return stack[0:k]

    def merge(self, subsequence1, subsequence2):
        ans = []
        while subsequence1 or subsequence2:
            bigger = subsequence1 if subsequence1 > subsequence2 else subsequence2
            ans.append(bigger.pop(0))
        return ans
