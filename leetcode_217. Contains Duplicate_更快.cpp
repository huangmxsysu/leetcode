class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i : nums) {
            bool insert_suc = set.insert(i).second;
            if(!insert_suc) {
                return true;
            }
        }
        return false;
    }
};