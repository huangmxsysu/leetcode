int maximalSquare2(vector<vector<char>>& matrix) {
    int row = matrix.size();
    if( row == 0 ) return 0;
    int col = matrix[0].size() , max_dis = 0;
    vector<vector<int>> square( row+1 , vector<int>( col + 1 , 0 ) );
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= col; ++j){
            if(matrix[i-1][j-1] == '1')
                square[i][j] = min(min(square[i-1][j], square[i][j-1]), square[i-1][j-1]) + 1;
            max_dis = max(max_dis, square[i][j]);
        }
    }
    return max_dis*max_dis;
    }



for( int i = 0 ; i < count ; i ++ ){
    
    for( int j = 0 ; j < count ; j ++ ){
        
        for( int i = 1 ; i < count ; i ++ ){
            
            vector<int>::iterator iter = vec.begin();
        }
        for( vector<jk
            >::iterator iter = vec.begin(); iter != vec.end(); iter ++ ){
            
        }
    }
}