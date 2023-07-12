# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        else:
            if root.left == None and root.right == None:
                return 1
            elif root.left == None and root.right:
                return self.minDepth(root.right) + 1
            elif root.right == None and root.left:
                return self.minDepth(root.left) + 1
            else:
                return min(self.minDepth(root.left), self.minDepth(root.right)) + 1