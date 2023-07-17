# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        stack1, stack2 = [], []
        while l1:
            stack1.append(l1.val)
            l1 = l1.next
        while l2:
            stack2.append(l2.val)
            l2 = l2.next

        carry = 0
        head = None
        while stack1 or stack2 or carry:
            sum = carry # 더해서 추가된 자릿수 1은 여기서 반영
            if stack1:
                sum += stack1.pop()
            if stack2:
                sum += stack2.pop()

            carry = sum // 10
            curr = ListNode(sum % 10)
            curr.next = head
            head = curr

        return head
        
        
        
        
        
        
        
        
        
        
#         l1_cnt, l2_cnt = 0, 0
#         start1, start2 = l1, l2
#         ans = head = ListNode(0)
#         while l1 or l2:
#             if l1:
#                 l1_cnt += 1
#                 l1 = l1.next
#             if l2:
#                 l2_cnt += 1
#                 l2 = l2.next
#         l1, l2 = start1, start2

#         if l1_cnt > l2_cnt:
#             for _ in range(l1_cnt - l2_cnt):
#                 ans.next = l1
#                 l1 = l1.next
#                 ans = ans.next
#         elif l1_cnt < l2_cnt:
#             for _ in range(l2_cnt - l1_cnt):
#                 ans.next = l2
#                 l2 = l2.next
#                 ans = ans.next
        
#         if l1_cnt == l2_cnt == 1 and l1.val + l2.val >= 10:
#             ans.next = ListNode(1)
#             ans = ans.next
#             ans.next = ListNode((l1.val + l2.val) % 10)
#             ans = head
#             return ans.next
        
#         while l1.next and l2.next:
#             if l1.next.val + l2.next.val >= 10:
#                 ans.next = ListNode((l1.val + l2.val) % 10 + 1)
#             else:
#                 ans.next = ListNode((l1.val + l2.val) % 10)
#             l1, l2 = l1.next, l2.next
#             ans = ans.next
#         ans.next = ListNode((l1.val + l2.val) % 10)
#         ans = head
#         return ans.next