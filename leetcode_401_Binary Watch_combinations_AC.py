class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        from itertools import combinations
        def get_int_from_LED(n,k):
        	value = [2**i for i in range(k)]
        	comb = combinations(value,n)
        	ans = []
        	for item in comb:
        		ans += [sum(item)]
        	return ans
        ans = []
        for i in range(min(5,num+1)):
        	j = num - i
        	value4 = get_int_from_LED(i,4)
        	value6 = get_int_from_LED(j,6)
        	for v4 in value4:
        		for v6 in value6:
        			if v4 < 12 and v6 < 60:
	        			temp = str(v6) if v6 > 9 else "0" + str(v6)
	        			ans.append(str(v4) + ":" + temp)
        return ans

