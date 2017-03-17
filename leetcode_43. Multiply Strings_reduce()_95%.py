class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = reduce(lambda x, y: x * 10 + y, [ord(i) - 48 for i in num1]) # '0' is 48 in ascii
        num2 = reduce(lambda x, y: x * 10 + y, [ord(i) - 48 for i in num2])
        return str(num1 * num2)
        