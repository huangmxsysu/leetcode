bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         if(nums.size() < 2) return false;
         vector<pair<long,int>> v;
         for(int i = 0; i < nums.size(); i++){
             v.push_back(pair<long,int>((long)nums[i],i));
         }
         sort(v.begin(),v.end(),cmp);
         for(int i = 0; i < nums.size(); i++){
             int j = i + 1;
             while(j < v.size()){
                 if(v[j].first-v[i].first > t)  break;
                 else if(v[i].second-v[j].second <= k && v[i].second-v[j].second >= -1*k){
                     return true;
                 }
                 else
                     j++;
             }
         }
         return false;
    }
    
    static bool cmp(pair<long,int> a, pair<long,int> b){
         return a.first < b.first;
    }