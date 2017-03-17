class Solution(object):
def letterCombinations(self, digits):
    dic, res = {'0':' ', '1':'*', '2':'abc', '3':'def', '4':'ghi','5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'} , []
    for x in digits:
        res = [pre + c for c in dic[x] for pre in res or ['']]
    return res
