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
        ListNode * pre = head;
        int count = 0;
        while( pre != NULL ){
            count ++;
            pre = pre->next;
        }
        int m = count - n - 1;
        int c = 0;
        ListNode * p = head;
        if( m == -1 ) return head->next;
        while( c != m ){
           c ++;
           p = p->next;
        }   
        ListNode *temp = p->next->next;
        if(temp == NULL) p->next = NULL;
        else p->next = temp;
        return head;
    }
};