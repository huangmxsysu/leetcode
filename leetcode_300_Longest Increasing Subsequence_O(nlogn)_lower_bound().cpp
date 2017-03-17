class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0;i<nums.size();i++){
            vector<int>::iterator iter = lower_bound(dp.begin(),dp.end(),nums[i]);
            if(iter == dp.end()){
                dp.push_back(nums[i]);
            }
            else *iter = nums[i];
        }
        return dp.size();
    }
};