class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for (auto& num: nums) {
            min_num = std::min(min_num, num);
            max_num = std::max(max_num, num);
        }
        long long bucket_width = static_cast<long long>(t) + 1;
        int size = (static_cast<long long>(max_num) - static_cast<long long>(min_num)) / bucket_width + 1;
        int* bucket = new int[size];
        memset(bucket, -1, sizeof(int) * size);
        for (int i = 0; i < nums.size(); i++) {
            int bucket_idx = (static_cast<long long>(nums[i])-min_num) / bucket_width;
            if (bucket[bucket_idx] >= 0)
                return true;
            bucket[bucket_idx] = i;
            if (bucket_idx >= 1) {
                int j = bucket[bucket_idx-1];
                if (j >= 0 && abs(static_cast<long long>(nums[i]) - nums[j]) <= t)
                    return true;
            }
            if (bucket_idx < size-1) {
                int l = bucket[bucket_idx+1];
                if (l >= 0 && abs(static_cast<long long>(nums[i]) - nums[l]) <= t)
                    return true;
            }
            if (i >= k) {
                bucket[(nums[i-k] - min_num) / bucket_width] = -1;
            }
        }
        return false;
    }
};