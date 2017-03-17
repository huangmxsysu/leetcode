class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if( root == NULL ) return false;
        else return has( root , sum );
    }
    bool has( TreeNode * root , int sum ){
        if( root == NULL )    return sum == 0? true:false;
        else if( root->left == NULL && root->right == NULL ) return sum == root->val? true:false;
        else    return hasPathSum( root->left , sum - root->val ) || hasPathSum( root->right , sum - root->val );
    }
};