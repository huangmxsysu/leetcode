def removeNthFromEnd(self, head, n):
    self.next, nodelist  = head, [self]
    while head.next:
        if len(nodelist) == n:
            nodelist.pop(0)
        nodelist += head,
        head = head.next
    nodelist[0].next = nodelist[0].next.next 
    return self.next