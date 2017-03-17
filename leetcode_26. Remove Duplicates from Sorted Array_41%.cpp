class Solution {  
public:  
    int removeDuplicates(vector<int>& nums)  
    {  
        int ans = 1;
        if( nums.size() <= 1 ) return nums.size();
        int size = nums.size();
        for(int i = 1 ; i < size; i ++ ){
            if( nums[i] != nums[i-1]){
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }  
};  