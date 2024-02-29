# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def size_of_linked_list_SW(self, head):
        size = 0
        current = head
        while current:
            size += 1
            current = current.next
        return size
    
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = self.size_of_linked_list_SW(head)
        # 각 부분 리스트의 기본 길이와 추가될 노드 수 계산
        part_length, extra_nodes = divmod(n, k)

        # 결과 리스트 초기화
        parts = []

        current = head
        for i in range(k):
            head = current
            # 현재 부분 리스트의 길이 설정 (기본 길이 + 추가 노드 여부)
            for j in range(part_length + (i < extra_nodes) - 1):
                if current:
                    current = current.next

            # 다음 부분 리스트로 넘어가기 전에 현재 부분 리스트 분리
            if current:
                next_part = current.next
                current.next = None
                current = next_part

            parts.append(head)

        return parts
        