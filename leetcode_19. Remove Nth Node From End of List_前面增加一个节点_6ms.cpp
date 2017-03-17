/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head == NULL ) return NULL;
        ListNode * new_head = new ListNode(0);
        new_head->next = head;
        ListNode * current = new_head, * end = new_head;
        for(int i = 0 ; i <= n ; i ++ ) end = end->next;
        while( end ){
            current = current->next;
            end = end->next;
        }
        current->next = current->next->next;
        return new_head->next;
        
    }
};