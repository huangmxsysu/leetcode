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
    ListNode* sortList(ListNode* head) {
        if( head == NULL ) return head;
        vector<int> vec;
        while( head != NULL ){
            vec.push_back(head->val);
            head = head->next;
        }
        int size = vec.size();
        merge_sort( vec , 0 , size - 1 );
        ListNode * List = new ListNode(vec[0]);
        ListNode * ans = List;
        for( int i = 1 ; i < size ; i ++ ){
            ListNode * temp = new ListNode(vec[i]);
            ans->next = temp;
            ans = ans->next;
        }
        return List;
        
    }
    void merge( vector<int>& a , int low , int mid , int high ){
        vector<int> temp( high - low + 1 , 0 );
    	int i = low , j = mid+1 , m = mid , n = high , k = 0;
    	while( i <= m && j <= n ){
    		if( a[i] < a[j] ) temp[k++] = a[i++];
    		else temp[k++] = a[j++];
    	}
    	while( i <= m ) temp[k++] = a[i++];
    	while( j <= n ) temp[k++] = a[j++];
    	for( int g = 0 ; g < k ; g ++ ) a[low+g] = temp[g];
    }
    void merge_sort( vector<int>& a , int low , int high ){
        if( low < high ){
            int mid = ( low + high )/2;
    		merge_sort( a , low , mid );
    		merge_sort( a , mid+1 , high );
    		merge( a , low , mid , high );
        }
    }
};