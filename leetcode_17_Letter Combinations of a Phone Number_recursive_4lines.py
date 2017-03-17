class Solution(object):
def letterCombinations(self, digits):
    dic = {'0':' ', '1':'*', '2':'abc', '3':'def', '4':'ghi','5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'} 
    return [a + b for a in dic.get(digits[:1], '') for b in self.letterCombinations(digits[1:]) or [''] ] or []