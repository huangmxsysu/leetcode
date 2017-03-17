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
        ListNode * pre = NULL, * current = head, * end = head;
        for(int i = 0 ; i < n ; i ++ ) end = end->next;
        while( end ){
            pre = current;
            current = current->next;
            end = end->next;
        }
        if( pre == NULL ) return head->next;
        else pre->next = current->next;
        return head;
        
    }
};