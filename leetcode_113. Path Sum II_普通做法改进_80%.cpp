class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        vector<vector<int>> res ;
        dfs( root , sum , temp , res );
        return res;
    }
    void dfs( TreeNode * root , int sum , vector<int>& temp , vector<vector<int>> & res ){
        if( ! root ) return;
        temp.push_back( root->val );
        if( !root->left && !root->right )
            if( sum == root->val )     res.push_back( temp );
        dfs( root->left , sum - root->val , temp , res );
        dfs( root->right , sum - root->val , temp , res );
        temp.pop_back();
    }
};