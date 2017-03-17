class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        new_list = ListNode(0)
        new_list.next = l1
        prev, head_of_1, head_of_2 = new_list, l1, l2

        while head_of_2:
            if not head_of_1:
                prev.next = head_of_2
                break
            if head_of_1.val > head_of_2.val:
                temp = head_of_2
                head_of_2 = head_of_2.next
                prev.next = temp
                temp.next = head_of_1
                prev = prev.next
            else:
                head_of_1, prev = head_of_1.next, head_of_1
        return new_list.next
