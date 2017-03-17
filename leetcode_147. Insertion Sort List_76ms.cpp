class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( head == NULL ){
			return head;
		}
		
		ListNode* helper = new ListNode(0); //new starter of the sorted list
		ListNode* cur = head; //the node will be inserted
		ListNode* pre = helper; //insert node between pre and pre.next
		ListNode* next = NULL; //the next node will be inserted
		//not the end of input list
		while( cur != NULL ){
			next = cur->next;
			//find the right place to insert
			while( pre->next != NULL && pre->next->val < cur->val ){
				pre = pre->next;
			}
			//insert between pre and pre.next
			cur->next = pre->next;
			pre->next = cur;
			pre = helper;
			cur = next;
		}
		
		return helper->next;
    }
};