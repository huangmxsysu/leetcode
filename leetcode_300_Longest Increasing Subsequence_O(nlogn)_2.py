def lengthOfLIS(self, nums):
	dp = []
	for items in range(nums):
		left,right = 0,len(dp)
		while left<right:
			mid = left + (right-left)/2
			if(dp[mid]<items):
				left = mid + 1
			else:
				right = mid
		if right >= len(dp):
			dp.append(items)
		else:
			dp[right] = items
	return len(dp)

