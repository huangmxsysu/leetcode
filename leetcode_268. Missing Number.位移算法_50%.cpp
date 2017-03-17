 
#define BITSPERWORD 32  
#define SHIFT 5  
#define MASK 0x1F  
#define N 100000 
int a[1 + N/BITSPERWORD]; 
void set_(int i) {        a[i>>SHIFT] |=  (1<<(i & MASK)); }  
void clr(int i) {        a[i>>SHIFT] &= ~(1<<(i & MASK)); }  
int  test(int i){ return a[i>>SHIFT] &   (1<<(i & MASK)); }   
class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i <= nums.size(); i ++ )  vclr(i);
        for(int i = 0; i < nums.size(); i ++ )  set_(nums[i]);
        for(int i = 0; i < nums.size(); i ++ )	if(!test(i)) return i;
        return nums.size();
    }
};