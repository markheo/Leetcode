"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head

        pseudoHead = Node(0, None, head, None)
        prev = pseudoHead

        stack = [head]

        while stack:
            curr = stack.pop()

            prev.next = curr
            curr.prev = prev

            if curr.next:
                stack.append(curr.next)
                curr.next = None  # Detach next pointer

            if curr.child:
                stack.append(curr.child)
                curr.child = None  # Detach child pointer

            prev = curr

        # Detach the pseudo head from the real head
        pseudoHead.next.prev = None
        return pseudoHead.next
        