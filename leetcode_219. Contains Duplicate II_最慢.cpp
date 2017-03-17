class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> my_map;
        //unordered_map 46%
        for(int i = 0; i < nums.size(); i ++ ){
            my_map[nums[i]] = -1;
        }
        int flag = 0;
        for(int i = 0; i < nums.size(); i ++ ){
            if(my_map[nums[i]] == -1) my_map[nums[i]] = i;
            else{
                if( i - my_map[nums[i]] <= k ){
                    flag = 1;
                    break;
                }
                my_map[nums[i]] = i;
            }
        }
        return flag == 1?true:false;
        
    }
};