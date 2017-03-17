class Solution(object):
    def longestSubstring(self, s, k):
    	ans,low,size = 0,0,len(s)
    	while low + k < size:
    		count = [0]*26
    		mask,max_index = 0,low
    		for high in range(low,size):
    			chr_index = ord(s[high])-97
    			count[chr_index] += 1
    			if count[chr_index] < k:
    				mask |= (1<<chr_index)
    			else:
    				mask &= (~(1<<chr_index))
    			if not mask:
    				ans = max(ans,high - low + 1)
    				max_index = high
    		low = max_index + 1
    	return ans