# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None or root == p or root == q:
            return root

        # 왼쪽과 오른쪽 서브트리에서 LCA 탐색
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # 왼쪽과 오른쪽 서브트리에서 각각 하나씩 찾은 경우 현재 노드가 LCA
        if left and right:
            return root

        # 하나의 서브트리에서만 찾은 경우 해당 서브트리의 결과 반환
        return left if left else right