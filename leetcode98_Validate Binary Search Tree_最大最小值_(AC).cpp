class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	return min_max_judge(root,INT_MIN,INT_MAX);
    }
    bool min_max_judge(TreeNode* root,int min_value, int max_value){
    	if(root == NULL) return true;
    	if(root->val < max_value && root->val > min_value && (min_max_judge(root->left,min_value,root->val) && min_max_judge(root->right,root->val, max_value)))
    		return true;
    	else
    		return false;
    }

}
//不过
