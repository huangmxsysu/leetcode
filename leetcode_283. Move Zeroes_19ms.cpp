class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size() , count = 0;
        for( int i = 0 ; i < size ; i ++ ){
            if( nums[i] != 0 ){
                swap( nums[i] , nums[count] );
                count ++;
            }
        }
    }
};