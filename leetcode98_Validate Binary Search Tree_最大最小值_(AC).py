# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:  
    def isValidBST(self, root):  
    	return self.min_max_search(root,-2**31-1,2**31)#注意测试样例
    def min_max_search(self, root, min, max):
    	if root is None:
    		return True
    	return root.val < max and root.val > min and self.min_max_search(root.left,min,root.val) and self.min_max_search(root.right,root.val,max)