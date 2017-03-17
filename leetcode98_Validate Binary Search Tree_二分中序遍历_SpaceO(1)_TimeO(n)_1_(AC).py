# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

    class Solution(object):
        
        def oder_search(self,root,flags,pres,flag1s):
            global flag
            global flag1
            global pre
            flag = flags
            flag1 = flag1s
            pre = pres
            if root is None:
                return
            self.oder_search(root.left,flag,pre,flag1)
            if(flag1):
                pre = root.val
                flag1 = False
            else:
                if root.val <= pre:
                    flag = 1
                    return
            pre = root.val
            self.oder_search(root.right,flag,pre,flag1)
            
        def isValidBST(self, root):
            global flag
            global flag1
            global pre
            if root is None:
                return True
            if root.left == None and root.right == None:
                return True
            flag = 0
            pre = 0
            flag1 = True
            self.oder_search(root,flag,pre,flag1)
            if flag is 1:
                return False
            return True
        
        
            
            """
            :type root: TreeNode
            :rtype: bool
            """