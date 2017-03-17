class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        comp = lambda a,b:1 if a+b>b+a else -1
        #comp = lambda a,b:-1 if a+b<b+a else 0
        #comp = lambda a,b:0 if a+b>b+a else -1
        #comp = lambda a,b:1 if a+b>b+a else 0  false
        num_to_str = map(str,nums)
        num_to_str.sort(cmp = comp,reverse = True)
        # num_to_str.sort(cmp = lambda a,b:-1 if a+b<b+a else 0,reverse = True) #慢
        # num_to_str.sort(cmp = lambda a,b:cmp(b+a,a+b),reverse = True) #not cmp(a+b,b+a)
        #return str(int(''.join(num_to_str)))
        return '0' if num_to_str[0] == '0' else ''.join(num_to_str)
        #return str(int("".join(sorted([str(x) for x in nums], cmp = lambda a, b: int(b + a) - int(a + b)))))