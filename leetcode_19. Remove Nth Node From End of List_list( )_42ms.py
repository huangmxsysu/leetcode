# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution(object):
    def removeNthFromEnd(self, head, n):
        collection=list();
        ptr=head;
        collection.append(ptr)
        while ptr.next is not None:
            collection.append(ptr.next)
            ptr=ptr.next
        length=len(collection);
        if length-n==0 and length>1:
            return collection[1]
        elif length-n==0 and length==1:
            return None
        elif n>1:
            collection[length-n-1].next=collection[length-n+1]
            return head
        elif n==1:
            collection[length-2].next=None
            return head