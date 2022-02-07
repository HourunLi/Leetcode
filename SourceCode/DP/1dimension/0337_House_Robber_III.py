# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution(object):
    memo = {}

    def rob(self, root):
        if root == None:
            return 0
        if root in self.memo:
            return self.memo[root]

        leftChild, rightChild = root.left, root.right
        lval = self.rob(leftChild.left) + \
            self.rob(leftChild.right) if leftChild is not None else 0
        rval = self.rob(rightChild.left) + \
            self.rob(rightChild.right) if rightChild is not None else 0
        val = max(root.val + lval + rval,
                  self.rob(root.left) + self.rob(root.right))
        self.memo[root] = val
        return val


# optimized
class Solution(object):
    def rob(self, root):
        def rob_(root):
            if not root:
                return 0, 0
            ls, ln = rob_(root.left)
            rs, rn = rob_(root.right)
            return root.val + ln + rn, max(ls, ln) + max(rs, rn)
        return max(rob_(root))
