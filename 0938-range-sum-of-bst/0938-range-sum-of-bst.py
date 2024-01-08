# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        from collections import deque
        ans = 0
        q = deque([root])

        while q:
            curr = q.popleft()
            if curr == None:
                return

            if curr.val >= low and curr.val <= high:
                ans += curr.val

            if curr.left:
                q.append(curr.left)
            if curr.right:
                q.append(curr.right)


        return ans