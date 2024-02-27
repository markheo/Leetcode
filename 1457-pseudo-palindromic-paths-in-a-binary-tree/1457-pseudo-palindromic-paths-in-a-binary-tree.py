# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def is_pseudo_palindromic(path: dict) -> bool:
            one_odd = False
            for count in path.values():
                if count % 2 == 1:
                    if one_odd:
                        return False
                    one_odd = True
            return True

        def helper(node: Optional[TreeNode], path: dict, num_pseudo_palindromic: list):
            if node:
                path[node.val] += 1
                if not node.left and not node.right:
                    if is_pseudo_palindromic(path):
                        num_pseudo_palindromic[0] += 1
                helper(node.left, path, num_pseudo_palindromic)
                helper(node.right, path, num_pseudo_palindromic)
                path[node.val] -= 1
                
        num_pseudo_palindromic = [0]
        helper(root, defaultdict(int), num_pseudo_palindromic)
        return num_pseudo_palindromic[0]