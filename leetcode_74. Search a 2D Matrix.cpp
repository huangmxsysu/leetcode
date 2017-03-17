class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int k = 0;
        for( int i = row-1; i >= 0; i-- ){
            if( matrix[i][0] <= target ){
                k = i;
                break;
            }
        }
        for( int j = 0; j < col; j ++ ){
            if( matrix[k][j] == target ) return true;
        }
        return false;
        
    }
};