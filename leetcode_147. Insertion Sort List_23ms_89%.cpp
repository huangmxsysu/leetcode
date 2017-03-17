class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( !head || !head->next ) return head;
        ListNode * new_list = new ListNode(0);
        new_list->next = head;
        ListNode * pre_flag = head;
        ListNode * flag = head->next;
        bool boo = false;
        while(flag != NULL){
            if(pre_flag->val > flag->val){
                ListNode * temp = new_list->next;
                ListNode * pre = new_list;
                boo = false;
                while( temp != flag ){
                    if( temp->val <= flag->val ){
                        temp = temp->next;
                        pre = pre->next;
                    }
                    else{
                        ListNode * temp_node = new ListNode(flag->val);
                        flag = flag->next;
                        pre_flag->next = flag; 
                        temp_node->next = temp;
                        pre->next = temp_node;
                        break;
                    }
                }
            }
            
            else{
                pre_flag = flag;
                flag = flag->next;
            }
            
        }
        return new_list->next;
        
    }
};