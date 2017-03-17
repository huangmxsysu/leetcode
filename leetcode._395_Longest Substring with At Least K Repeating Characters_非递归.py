class Solution(object):
    def longestSubstring(self, s, k):
        low, r, n, total = 0, 0, len(s), collections.Counter(s)

        while low < n:
            while low < n and total[s[low]] < k:
                total[s[low]] -= 1
                low += 1

            if low >= n:
                break

            high, counter, mask, index = low, collections.defaultdict(
                int), 0, low

            while high < n and total[s[high]] >= k:
                counter[s[high]] += 1

                bit = 1 << ord(s[high]) - 97
                if counter[s[high]] < k:
                    mask |= bit
                else:
                    mask &= ~bit

                if not mask:
                    index = high
                    r = max(r, high - low + 1)

                high += 1

            while low <= index:
                total[low] -= 1
                low += 1

        return r