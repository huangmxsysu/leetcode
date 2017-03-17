//时间复杂度为O(m+n)
class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();

		int i = 0, j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				j--;
			else
				i++;
		}
		return false;
	}
};

bool search_2( vector<vector<int>> & matrix, int low_x, int low_y, int high_x, int high_y, int target ){
	int i = low_y, j = high_x;
	while( i < high_y && j >= low_x ){
		if( matrix[i][j] == target ) return true;
		else if( matrix[i][j] > target ) j--;
		else i++;
	}
	return false;
}