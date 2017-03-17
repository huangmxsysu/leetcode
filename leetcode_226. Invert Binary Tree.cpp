class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs( root );
        return root;
    }
    void dfs( TreeNode * root )
    {
        if( root == NULL || ( root->left == NULL && root->right == NULL ) ) return ;
        dfs( root->left );
        dfs( root->right );
        swap( root->left , root->right );
    }
};