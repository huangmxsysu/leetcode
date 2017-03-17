class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)  {
    unordered_my_map<int,int> my_map;
    for(int i = 0; i < nums.size(); i++){
      if(my_map.count(nums[i]) && (i - my_map[nums[i]] <= k)) return true;
      my_map[nums[i]] = i;
    }
    return false;
}
};