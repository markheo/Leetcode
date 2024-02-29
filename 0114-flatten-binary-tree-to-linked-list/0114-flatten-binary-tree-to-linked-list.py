# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def helper(root):
            # 기본 경우: 노드가 None이면 None 반환
            if not root:
                return None

            # 리프 노드인 경우 자기 자신을 반환
            if not root.left and not root.right:
                return root

            # 왼쪽 서브트리를 평탄화
            left_tail = helper(root.left)

            # 오른쪽 서브트리를 평탄화
            right_tail = helper(root.right)

            # 왼쪽 서브트리가 있으면, 왼쪽 서브트리를 오른쪽으로 옮기고,
            # 왼쪽 서브트리의 마지막을 오른쪽 서브트리와 연결
            if left_tail:
                left_tail.right = root.right
                root.right = root.left
                root.left = None

            # 마지막 방문한 노드를 반환
            # 오른쪽 서브트리의 마지막 노드가 존재하면 그것을, 그렇지 않으면 왼쪽 서브트리의 마지막 노드를 반환
            return right_tail if right_tail else left_tail

        helper(root)