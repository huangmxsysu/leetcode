class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * new_list = new ListNode(0);
        new_list->next = head;
        ListNode * flag = head;
        ListNode * pre = new_list;
        while(flag){
            if( flag->next && flag->next->val < flag->val ){
                while( pre->next && pre->next->val < flag->next->val ) pre = pre->next;
                /* Insert flag -> next after pre.*/
                ListNode * temp = pre->next;
                pre->next = flag->next;
                flag->next = flag->next->next;
                pre->next->next = temp;
                /* Move pre back to new_list. */
                pre = new_list;
            }
            else{
                flag = flag->next;
            }
        }
        ListNode * ans = new_list->next;
        delete new_list;
        return ans;
    }
};