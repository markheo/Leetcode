# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def DFS(node, low, high):
            nonlocal ans
            if node == None:
                return

            if low <= node.val <= high:
                ans += node.val
            # low보다 작거나 같으면 더 작은 왼쪽 탐색할 필요 없음(하한선 도달)
            if node.val > low:
                DFS(node.left, low, high)
            # high보다 크거나 같으면 더 큰 오른쪽 탐색할 필요 없음(상한선 도달)
            if node.val < high:
                DFS(node.right, low, high)
        ans = 0
        DFS(root, low, high)
        return ans