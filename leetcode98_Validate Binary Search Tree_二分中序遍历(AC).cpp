class Solution {
public:
    vector<int> oder_vector;  
    bool isValidBST(TreeNode* root) {
    	if(root==NULL) return true;
    	if(root->left==NULL&&root->right==NULL) return true;
    	oder_search(root,oder_vector);
        for(int i=1;i<oder_vector.size();i++)
            if(oder_vector[i] <= oder_vector[i-1]) return false;
        return true;
    }
    void oder_search(TreeNode* root,vector<int>& oder_vector){
        if(root==NULL) return;
        oder_search(root->left,oder_vector);
        oder_vector.push_back(root->val);
        oder_search(root->right,oder_vector);
    }
    
};

//21.5%