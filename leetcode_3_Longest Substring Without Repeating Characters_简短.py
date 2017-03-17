class Solution(object):
    def lengthOfLongestSubstring(self, s):
        l_substr, l_suffix = '', ''
        for each in s:
            l_suffix, l_substr = each in l_suffix and l_suffix[l_suffix.index(each) + 1:] + each or l_suffix + each, max((l_suffix, l_substr), key=len)
        return len(l_substr)