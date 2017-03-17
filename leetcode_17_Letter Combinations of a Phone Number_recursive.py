class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        m = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        ans = []
        if len(digits) == 0: return []
        if len(digits) == 1:
            return list(m[digits[0]])
        else:
            result = self.letterCombinations(digits[1:])
            for r in result:
                for j in m[digits[0]]:
                    ans.append(j + r)
        return ans