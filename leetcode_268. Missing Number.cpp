class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(),nums.end());
        for( int a:nums ){
            if(a != count) return count;
            count++;
        }
        return count;
        
    }
};