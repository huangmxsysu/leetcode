# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution(object):
    def removeNthFromEnd(self, head, n):
        current = head
        end = head
        for i in range(0,n):
            end = end.next
        if(end == None):
            return head.next
        while(end.next != None):
            end = end.next
            current = current.next
        current.next = current.next.next
        return head