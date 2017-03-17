class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int consecutiveCompare = nums[0]-1;
        int counter = 0;
        int longestCounter = 0;
        
        for (int i=0; i<nums.size(); i++){
            if (consecutiveCompare == nums[i]) { //handle duplicates
                continue;
            }
            else if (consecutiveCompare+1 != nums[i]){ //found the end of a sequence, now reset the sequence
                consecutiveCompare = nums[i];
                longestCounter = max(longestCounter, counter);
                counter = 1;
            }
            else { //found an element of a sequence, now continue to the next element.
                consecutiveCompare = nums[i];
                counter++;
            }
        }
        
        longestCounter = max(longestCounter, counter);
        
        return longestCounter;
    }
};