# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None

        # 두 포인터 초기화
        ptrA = headA
        ptrB = headB

        # 두 포인터가 만날 때까지 반복
        while ptrA != ptrB:
            # 포인터 A가 끝에 도달하면 B의 시작으로 이동, 그렇지 않으면 다음 노드로 이동
            ptrA = ptrA.next if ptrA else headB
            # 포인터 B가 끝에 도달하면 A의 시작으로 이동, 그렇지 않으면 다음 노드로 이동
            ptrB = ptrB.next if ptrB else headA

        # 교차 노드 반환 (교차 노드가 없는 경우 None 반환)
        return ptrA
        