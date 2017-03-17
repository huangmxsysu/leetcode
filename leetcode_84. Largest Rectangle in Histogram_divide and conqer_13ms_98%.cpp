class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        return getMax(heights, 0, heights.size());
    }    
    int getMax(vector<int>& heights, int s, int e) {
        if (s + 1 >= e) return heights[s];
        int min = s;
        bool sorted = true;
        for (int i = s; i < e; i++) {
            if (i > s && heights[i] < heights[i - 1]) sorted = false;
            if (heights[min] > heights[i]) min = i;
        }
        if (sorted) {
            int max_area = 0;
            for (int i = s; i < e; i++) {
                max_area = max(max_area, heights[i] * (e - i));
            }
            return max_area;
        }
        int left = (min > s) ? getMax(heights, s, min) : 0;
        int right = (min < e - 1) ? getMax(heights, min + 1, e) : 0;
        return max(max(left, right), (e - s) * heights[min]);
    }
};