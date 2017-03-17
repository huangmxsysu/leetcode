class Solution:
    def largestNumber(self,nums):
        num_to_str = ''.join(sorted([str(x) for x in nums],cmp=lambda a,b:cmp(b+a,a+b)))
        return num_to_str if num_to_str[0] !='0' else "0"