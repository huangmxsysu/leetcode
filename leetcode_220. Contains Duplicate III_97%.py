def containsNearbyAlmostDuplicate(self, nums, k, t):
        d = {}
        for i, n in enumerate(nums):
            bucket, offset = (n / t, 1) if t != 0 else (n, 0)
            for b in range(bucket - offset, bucket + offset + 1):
                if b in d and abs(i - d[b][0]) <= k and abs(n - d[b][1]) <= t:
                    return True
            d[bucket] = (i, n)
        return False