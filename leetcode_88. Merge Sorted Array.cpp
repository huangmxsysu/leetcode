class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> new_vec;
        int i = 0 , j = 0 ;
        while( i < m && j < n ){
            if( nums1[i] < nums2[j] ) new_vec.push_back(nums1[i++]);
            else new_vec.push_back(nums2[j++]);
        }
        while(i < m) new_vec.push_back(nums1[i++]);
        while(j < n) new_vec.push_back(nums2[j++]);
        nums1.clear();
        for( int i = 0 ; i < new_vec.size() ; i ++ ){
            nums1.push_back(new_vec[i]);
        }
    }
};