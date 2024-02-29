# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        ans = []
        # 스택 초기화
        stack = []
        # 현재 노드와 인덱스를 저장할 리스트
        current_nodes = []

        # 연결 리스트 순회
        curr = head
        while curr:
            # 현재 노드의 값을 결과 리스트에 추가 (나중에 업데이트 될 예정)
            ans.append(curr.val)
            # 현재 노드를 current_nodes에 추가
            current_nodes.append(curr.val)

            # 스택이 비어있지 않고 현재 노드의 값이 스택의 top에 있는 노드의 값보다 큰 경우
            while stack and curr.val > current_nodes[stack[-1]]:
                # 스택에서 pop하고, 결과 리스트의 해당 인덱스의 값을 현재 노드의 값으로 업데이트
                ans[stack.pop()] = curr.val

            # 현재 노드의 인덱스를 스택에 push
            stack.append(len(current_nodes) - 1)
            # 다음 노드로 이동
            curr = curr.next

        for index in stack:
            ans[index] = 0
            
        return ans