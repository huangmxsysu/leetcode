class Solution {
public:
    int get( int n , int k , int & yushu ){
        int temp = 1;
        for( int i = n-1 ; i > 0 ; i -- )   temp *= i;
        yushu = k % temp;
        if(yushu)
        return k/temp + 1;
        else
        {
            yushu = temp;
            return k/temp;
        }
        
    }
    string getPermutation(int n, int k) {
        string s = "";
        int yushu = 0;
        int first = get( n , k , yushu );
        cout<<" first = " << first << " yushu = " << yushu  << endl;
        vector<int> nums;
        for( int i = 1 ; i <= n ; i ++ ){
            if( i != first ) nums.push_back(i);
        }
        int count = 1 ;
        while( count < yushu ){
            nextPermutation( nums );
            count++;
        }
        s += char( first + '0');
        for( int i = 0 ; i < nums.size() ; i ++ ){
            s += char(nums[i] + '0');
        }
        return s;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = nums.size()-2; i >= 0; --i)
        {
            if (nums[i] < nums[i+1]) break;
        }
        
        // reverse all the numbers after violated number
        reverse(begin(nums)+i+1, end(nums));
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(begin(nums)+i+1, end(nums), nums[i]);
        // swap them, done!
        swap(nums[i], *itr);
    }
};