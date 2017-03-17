class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if( root == NULL ) return 0;
        return dfs( root , sum ) + pathSum( root->left , sum ) + pathSum( root->right , sum );
    }
    int dfs( TreeNode * root , int sum ){
        if( root == NULL ) return 0;
        return ( root->val == sum ) + dfs( root->left , sum - root->val) + dfs( root->right , sum - root->val);
    }
};