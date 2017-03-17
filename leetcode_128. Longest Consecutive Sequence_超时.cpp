class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            if(mp[nums[i]]) continue;
            mp[nums[i]] = 1;
            if(mp[nums[i] - 1]) mp[nums[i]] += mp[nums[i] - 1];
            int k = 1;
            while(mp[nums[i] + k]){
                mp[nums[i] + k] = 1;
                mp[nums[i] + k] += mp[nums[i] + k - 1];
                k ++;
            }
        }
        int ans = 0;
        map<int,int>::iterator iter;
        for( iter = mp.begin() ; iter != mp.end() ; iter ++ ){
            ans = max( ans , iter->second );
        }
        return ans;
    }
};