class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size() , count = 0;
        for( int i = 0 ; i < size ; i ++ ){
            if( nums[i] != val ){
                swap( nums[i] , nums[count] );
                count ++;
            }
        }
        int c = size - count;
        while( c ){
            nums.pop_back();
            c --;
        }
        return count;
    }
};