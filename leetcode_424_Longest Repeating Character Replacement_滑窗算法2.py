def characterReplacement(self, s, k):
    res = lo = hi = 0
    counts = collections.Counter()
    for hi in range(1, len(s)+1):
        counts[s[hi-1]] += 1
        max_char_n = counts.most_common(1)[0][1]
        if hi - lo - max_char_n > k:
            counts[s[lo]] -= 1
            lo += 1
    return hi - lo