#define BITSPERWORD 32  
#define SHIFT 5  
#define MASK 0x1F  
#define N 10000000  
int a[1 + N/BITSPERWORD]; 
void set_(int i) {        a[i>>SHIFT] |=  (1<<(i & MASK)); }  
void clr(int i) {        a[i>>SHIFT] &= ~(1<<(i & MASK)); }  
int  test(int i){ return a[i>>SHIFT] &   (1<<(i & MASK)); }  
  
 
class Solution {
    
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)return false;
        int i;  
    for (i = 0; i < nums.size(); i++)  
        clr(nums[i]);    
    for (i = 0; i < nums.size(); i++)  
    {
        if(test(nums[i]))return true;
        else set_(nums[i]);  
    }
   return false;
    }
};