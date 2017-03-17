class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        ListNode * new_list = new ListNode(0);
        ListNode * pre = new_list;
        while( l1 != NULL  && l2 != NULL ){
            if( l1->val < l2->val ){
                pre->next = l1;
                l1 = l1->next;
            }
            else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if( l1 )  pre->next = l1;
        else  pre->next = l2;
        return new_list->next;
        
    }
};