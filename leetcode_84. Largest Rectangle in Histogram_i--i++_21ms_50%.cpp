class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int size = heights.size();
        stack<int> s;
        int max_area = 0 ;
        for( int i = 0 ; i < size ; i ++ ){
            if( s.empty() || heights[s.top()] <= heights[i] ) s.push(i);
            else{
                int top = s.top();
                s.pop();
                max_area = max( max_area , heights[top] * ( s.empty() ? i : i - 1 - s.top() ) );
                i --; 
            }
        }
        return max_area;
    }
};