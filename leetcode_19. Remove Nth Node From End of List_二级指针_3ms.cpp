class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode** t1 = &head, *t2 = head;//t1 == pre   *t1 = current   (*t1)->next = current->next  
        for(int i = 0; i < n; ++i)
        {
            t2 = t2->next;
        }
        while(t2 != NULL)
        {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};