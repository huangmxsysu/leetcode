class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        int flag = 0;
        int pre = root->val;
        oder_search(root,flag,pre);
        if(flag == 1) return false;
        return true;
    }
    void oder_search(TreeNode* root,int & flag,int& pre){
        if(root==NULL) return;
        oder_search(root->left,flag,pre);
        if(root->val <= pre){
            flag = 1;
            return;
        }
        pre = root->val;

        oder_search(root->right,flag,pre);
    }
    
};
//86%