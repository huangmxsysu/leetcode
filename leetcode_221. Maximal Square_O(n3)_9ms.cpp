class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	int row = matrix.size();
    	if( row == 0 ) return 0 ;
    	int col = matrix[0].size() , max_dis = 0;
    	vector<vector<int>> vec( row , vector<int>( col , 0 ) );
    	for( int i = 0 ; i < row ; i ++ ){
    		for( int j = 0 ; j < col ; j ++ ){
    			if( matrix[i][j] == '1' ){
    				if( i - 1 >= 0 && j - 1 >= 0 ){
    					int dis = vec[i-1][j-1] , flag = 1;
    					for( ; flag <= dis ; flag ++ )	
    						if( matrix[i-flag][j] == '0' || matrix[i][j-flag] == '0' ) break;
    					vec[i][j] = flag;
    				}
    				else vec[i][j] = 1;
    			}
    			else vec[i][j] = 0;
    			max_dis = max( max_dis , vec[i][j] );
    		}
    	}
    	return max_dis*max_dis; 
    }
};