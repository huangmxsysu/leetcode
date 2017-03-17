/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(!valid_left(root->left, root->val)||!valid_right(root->right,root->val)) return false;
        return (isValidBST(root->left) && isValidBST(root->right));
    }
    bool valid_left(TreeNode* root, int value){
        if(root == NULL ) return true;
        if(root->val >= value) return false;
        return valid_left(root->left,value)&&valid_left(root->right,value);
    }
    bool valid_right(TreeNode* root, int value){
        if(root == NULL ) return true;
        if(root->val <= value) return false;
        return valid_right(root->left,value)&&valid_right(root->right,value);
    }
    
};
//4.98%