class Solution {
public:
    string largestNumber(vector<int>& nums) {
       sort(nums.begin(), nums.end(), [](int a, int b){ return to_string(a) + to_string(b) > to_string(b) + to_string(a);});
       string ans = accumulate(nums.begin(), nums.end(), string(), [](string &r, int a){return r + to_string(a);});
       return ans[0] == '0' ? "0" : ans;
       }
};