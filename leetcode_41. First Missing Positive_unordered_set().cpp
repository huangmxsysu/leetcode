class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int k = 1;
        while(1){
            if(s.find(k) == s.end())    return k;
            k++;
        }
    }
};