class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int& n) {
        ListNode * node = new ListNode(0);
        node->next = head;
        removeNode(node, n);
        return node->next;
    }
    
    void removeNode(ListNode* head, int& n){
        if(!head) return;
        removeNode(head->next, n);
        n--;
        if(n == -1) {
            head->next = head->next->next; 
        }
        return;
    }
};