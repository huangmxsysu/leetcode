class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int ans = 2;
        if( size <= 2 ) return size;
        int temp[size];
        temp[0] = nums[0];
        temp[1] = nums[1];
        for( int i = 2; i < size; i ++ ){
            if(nums[i] != nums[i-1] || (nums[i] == nums[i-1] && nums[i] != nums[i-2]))
            temp[ans++] = nums[i];
        }
        nums.clear();
        for(int i = 0 ; i < ans; i ++ ) {
            nums.push_back(temp[i]);
        }
        return nums.size();
        
    }
};