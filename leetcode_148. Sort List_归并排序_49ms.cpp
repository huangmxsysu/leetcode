class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if( !head || !head->next ) return head;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * second_head = slow->next;
        slow->next = NULL;
        return merge( sortList(head) , sortList(second_head) );
    }
    ListNode * merge( ListNode * left , ListNode * right ){
        ListNode * new_list = new ListNode(0);
        ListNode * temp = new_list;
        while( left && right ){
            if( left->val < right->val ){
                temp=temp->next = left;
                left = left->next;
            }
            else{
                temp = temp->next = right;
                right = right->next;
            }
        }
        if( left ) temp->next = left;
        else temp->next = right;
        return new_list->next;
    }
    
};