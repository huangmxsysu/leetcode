class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, compare > heap;
    ListNode head(0);
    ListNode *curNode = &head;
    int i, k, n = lists.size();
    for (i = 0; i < n; i++)
        if (lists[i]) heap.push(lists[i]);
    while (!heap.empty()){
        curNode->next = heap.top();
        heap.pop();
        curNode = curNode->next;
        if (curNode->next) heap.push(curNode->next);
    }
    return head.next;
}
struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
};