# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
   
        current = end = self
        self.next = head
        while end.next:
            if n:
                n -= 1
            else:
                current = current.next
            end = end.next
        current.next = current.next.next
        return self.next 