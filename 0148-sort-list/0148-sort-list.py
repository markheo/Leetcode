# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge_linked_list_SW(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1

        if l1.val <= l2.val:
            l3 = l1
            l3.next = self.merge_linked_list_SW(l1.next, l2)
        else:
            l3 = l2
            l3.next = self.merge_linked_list_SW(l1, l2.next)

        return l3

    def find_middle_SW(self, l):
        slow = l
        fast = l

        while fast and fast.next:
            # 추가
            if fast.next.next == None:
                return slow
            slow = slow.next # 1-2-3-4-5-6
            fast = fast.next.next # 1-3-5
            # print(slow.val, fast.val)
        return slow
    
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        # 절반으로 나누기
        mid = self.find_middle_SW(head)
        mid_next = mid.next
        mid.next = None # 리스트 분리

        # 재귀적으로 분할 및 병합
        left = self.sortList(head) # 앞의 절반
        right = self.sortList(mid_next) # 뒤의 절반

        return self.merge_linked_list_SW(left, right)
        