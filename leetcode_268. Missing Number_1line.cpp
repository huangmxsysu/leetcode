class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return 0.5 * nums.size() * (nums.size() + 1) - accumulate(nums.begin(), nums.end(), 0);
    }
};