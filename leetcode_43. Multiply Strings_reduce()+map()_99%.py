class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """       
        i = reduce(lambda x,y : 10 * x + y,map(lambda g:ord(g)-48,num1))
        j = reduce(lambda x,y : 10 * x + y,map(lambda g:ord(g)-48,num2))
        return str(i * j)