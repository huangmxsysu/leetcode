class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        curr, res, letter = 0, 0, set()
        for i, ch in enumerate(s):
            while ch in letter:
                letter.remove(s[curr])
                curr += 1
            letter.add(ch)
            res = max(res, i - curr + 1)
        return res