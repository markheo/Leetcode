# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse_linked_list(head):
            prev = None
            current = head
            while current:
                next_node = current.next
                current.next = prev
                prev = current
                current = next_node
            return prev
        
        # 연결 리스트 뒤집기
        reversed_head = reverse_linked_list(head)

        # 뒤집힌 리스트를 순회하면서 작은 노드 제거
        dummy = ListNode(0)
        dummy.next = reversed_head
        max_val = float('-inf')
        current = dummy
        while current.next:
            if current.next.val < max_val:
                current.next = current.next.next  # 노드 제거
            else:
                max_val = current.next.val
                current = current.next

        # 다시 리스트 뒤집기
        return reverse_linked_list(dummy.next)