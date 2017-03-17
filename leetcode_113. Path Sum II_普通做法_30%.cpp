class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        vector<vector<int>> res ;
        dfs( root , sum , temp , res );
        return res;
    }
    void dfs( TreeNode * root , int sum , vector<int> temp , vector<vector<int>> & res ){
        if( ! root ) return;
        if( !root->left && !root->right ){
            if( sum == root->val ){
                temp.push_back( root->val );
                res.push_back( temp );
            }
            return;
        }
        temp.push_back( root->val );
        if( root->left ) dfs( root->left , sum-root->val , temp , res );
        if( root->right ) dfs( root->right , sum - root->val , temp , res );
    }
};