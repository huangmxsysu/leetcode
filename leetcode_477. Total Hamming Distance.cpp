class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0 , size = nums.size();
        vector<int> flag( 32 , 0 );
        for( int k = 0 ; k < 32 ; k ++)
            for( int i = 0 ; i < size ; i ++ )  
                flag[k] += ( nums[i]>>k ) & 1;
        for( int k = 0 ; k < 32 ; k ++ )
            if(flag[k]) ans += ( size - flag[k] ) * flag[k];
        return ans;
    }
};