class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());
        vector<int> v;
        bool flag[nums.size()];
        for(int i=0;i<nums.size();++i) flag[i] = false;
        permute(res,v,nums,flag);
        return res;
    }
    
private:
    void permute(vector<vector<int> > &res,vector<int> &v,vector<int> &nums,bool *flag)
    {
        int i;
        for(i=0;i<nums.size();++i) if(!flag[i]) break;
        if(i == nums.size()) res.push_back(v);
        else{
            for(i=0;i<nums.size();++i)
            {
                if(!flag[i])
                {  
                    v.push_back(nums[i]);
                    flag[i] = true;
                    permute(res,v,nums,flag);
                    v.pop_back();
                    flag[i] = false;
	            while(i!=nums.size()-1 && nums[i+1] == nums[i]) ++i;
                }
            }
        }
    }
    
};