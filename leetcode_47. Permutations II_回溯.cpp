class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort( nums.begin() , nums.end() );
        generate(nums,res,0);
        return res;
    }
    void generate( vector<int>  nums , vector<vector<int> > & res , int pos ){
        if( pos == nums.size() - 1 ) res.push_back( nums );
        for( int i = pos ; i < nums.size() ; i ++ ){
            if( i != pos && nums[i] == nums[pos] ) continue;
            swap( nums[pos] , nums[i] );
            generate( nums, res , pos + 1 );
        }
    }
};