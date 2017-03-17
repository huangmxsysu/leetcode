class Solution(object):
    value = None
    def isValidBST(self, root):
        if root is None:
            return True
        ans = self.isValidBST(root.left)
        if(self.value is None):
            self.value = root.val
        else:
            if root.val <= self.value:
                ans = False
            self.value = root.val
        ans = ans and self.isValidBST(root.right)
        return ans 