class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	heights.push_back(0);
        int size = heights.size();
        stack<int> s;
        int max_area = 0 ;
        for( int i = 0 ; i < size ; i ++ ){
        	while( !s.empty() && heights[s.top()] > heights[i] ){
        		int top = s.top();
        		s.pop();
        		max_area = max( max_area , heights[top] * ( i - ( s.empty() ? -1 : s.top() ) - 1 ) );
        	}
        	s.push(i);
        }
        return max_area;
    }
};
