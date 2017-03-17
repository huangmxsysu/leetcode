class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* tail;
        quickSort(head,tail);
        return head;
    }
private:
    void quickSort(ListNode* &head,ListNode* &tail){
        if(head==nullptr)
            return;
        ListNode left_head(-1),right_head(-1);
        ListNode *left_tail=&left_head,*right_tail=&right_head;
        ListNode *pivot_head=head,*pivot_tail=head,*now=head->next;
        int key=pivot_head->val;
        //paritition
        while(now!=nullptr){
            if(now->val < key){
                left_tail->next=now;
                left_tail=now;
            } else if(now->val > key){
                right_tail->next=now;
                right_tail=now;
            } else {
            	pivot_tail->next=now;
            	pivot_tail=now;
            }
            now=now->next;
        }

        //deal with end node
        right_tail->next=nullptr;
        left_tail->next=nullptr;
        pivot_tail->next=nullptr;

        quickSort(left_head.next,left_tail);
        quickSort(right_head.next,right_tail);
		//connect pivot,sorted left part,sorted right part
        if(left_head.next!=nullptr && right_tail!=&right_head){
            //left part and right part is not null
            //L->P->R
            left_tail->next=pivot_head;
            pivot_tail->next=right_head.next;
            head=left_head.next;
            tail=right_tail;

        } else if(left_head.next!=nullptr){
            //left part is not null but right part is null
            //L->P
            left_tail->next=pivot_head;
            head=left_head.next;
            tail=pivot_tail;
        } else if(right_tail!=&right_head){
            //right part is not null but left part is null
            //P->R
            pivot_tail->next=right_head.next;
            head=pivot_head;
            tail=right_tail;
        }
        //no need to deal with two null situation.
    }
};