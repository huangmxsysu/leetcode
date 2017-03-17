class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0;i<nums.size();i++){
            int right = dp.size();
            int left = 0;
            while(left<right){
                int mid = left + (right-left)/2;
                if(dp[mid]<nums[i]) left = mid + 1;
                else right = mid;
            }
            if(right>=dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};