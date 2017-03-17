class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return len(set(s)) == len(set(zip(s, t))) == len(set(t))
        #
        return all(map({}.setdefault, a, b) == list(b) for a, b in ((s, t), (t, s)))
        #
	    f = lambda s: map({}.setdefault, s, range(len(s)))
	    return f(s) == f(t)
	    #
	    return [s.find(i) for i in s] == [t.find(j) for j in t]
	    #
	    return map(s.find, s) == map(t.find, t)