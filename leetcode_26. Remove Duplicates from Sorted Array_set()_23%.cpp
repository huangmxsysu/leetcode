class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        nums.clear();
        set<int>::iterator iter = s.begin();
        while(iter!=s.end()){
            nums.push_back(*iter);
            iter++;
        }
        return nums.size();
        
    }
};