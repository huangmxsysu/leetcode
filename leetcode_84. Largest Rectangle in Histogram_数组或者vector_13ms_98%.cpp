class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int cur = 0, max_area = 0, top = 0;
        int * stack = new int[heights.size()];
        //vector<int> stack( heights.size() , 0 );
        stack[top] = -1;
        for(int i = 0; i < heights.size(); ++i){
            while(top>0 && heights[stack[top]] >= heights[i]){
                cur = (i-stack[top-1]-1)*heights[stack[top]];
                top--;
                max_area = max(cur, max_area);
            }
            stack[++top] = i;
        }
        return max_area;
    }
};