class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if( row == 0 )	return 0;	
        int col = matrix[0].size();
        vector< int > heights( col , 0 ) ;
		int max_area = 0;
		heights.push_back(0);
		for( int i = 0 ; i < row ; i ++ ){
			int top = 0, cur = 0;
			vector<int> temp(heights.size() , 0);
			temp[top] = -1;
			for( int j = 0 ; j < heights.size() ; j++ ){
				if( j != heights.size() )  heights[j] = matrix[i][j] == '1' ? 1 + heights[j] : 0;
				while( top > 0 && heights[ temp[top] ] >= heights[j] ) {
				    cur= ( j - temp[top-1] - 1 )* heights[ temp[top] ] ;
				    top--;
				    max_area = max( max_area , cur );
				}
				temp[++top] = j;
			}
		}
		return max_area;
    }
};