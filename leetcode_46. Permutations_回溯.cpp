class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        generate(nums,res,0);
        return res;
    }
    void generate( vector<int> & nums , vector<vector<int> > & res , int pos )
    {
        if( pos == nums.size() - 1 ) res.push_back( nums );
        else{
            for( int i = pos ; i < nums.size() ; i ++ ){
                swap( nums[pos] , nums[i] );
                generate( nums, res , pos + 1 );
                swap( nums[pos] , nums[i] );
            }
        }
    }
};