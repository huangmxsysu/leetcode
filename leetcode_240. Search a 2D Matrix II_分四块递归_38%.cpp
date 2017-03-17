class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        return parti_search( matrix, 0, 0, col-1, row-1, target );
        
        
    }
    bool parti_search(vector<vector<int>> & matrix, int low_x, int low_y, int high_x, int high_y, int target ){
        if( high_x - low_x <= 10 && high_y - low_y <= 10 ){
            for( int i = low_y; i <= high_y; i ++ ){
                for( int j = low_x; j <= high_x; j ++ ){
                    if( matrix[i][j] == target ){
                        return true;
                    }
                }
            }
            return false;
        }
        
        int mid_x = ( low_x + high_x ) / 2;
        int mid_y = ( low_y + high_y ) / 2;
        bool temp1 = false, temp2 = false, temp3 = false, temp4 = false;
        if( matrix[low_y][low_x] <= target && matrix[mid_y][mid_x] >= target )
            temp1 = parti_search( matrix, low_x, low_y, mid_x, mid_y, target );
        if( temp1 == true ) return true;

        if( mid_y + 1 <= high_y && matrix[mid_y + 1][low_x] <= target && matrix[high_y][mid_x] >= target )
            temp2 = parti_search( matrix, low_x, mid_y + 1, mid_x, high_y, target );
        if( temp2 == true ) return true;

        if( mid_x + 1 <= high_x && matrix[low_y][mid_x + 1] <= target && matrix[mid_y][high_x] >= target )
            temp3 = parti_search( matrix, mid_x + 1, low_y, high_x, mid_y, target );
        if( temp3 == true ) return true;

        if( mid_x + 1 <= high_x && mid_y + 1 <= high_y && matrix[mid_y + 1][mid_x + 1] <= target && matrix[high_y][high_x] >= target )
            temp4 = parti_search( matrix, mid_x + 1, mid_y + 1, high_x, high_y, target );
        if( temp4 == true ) return true;

        return (temp1||temp2||temp3||temp4);
    }
};

[
[93,157,226, 308,365,  384,479, 539,557,652],
[118,234,287, 368,395,  432,480, 607,634,723],
[132,263,381, 453,525,  533,577, 650,707,800],

[171,307,473, 504,526,  596,643, 719,776,842],
[233,319,514, 571,668,  710,733, 777,875,886],

[318,362,555, 605,717,  782,809,884,889,940],
[349,415,622, 708,787,  795,824,921,957,1014],
[414,420,656, 789,813,  898,954,1052,1095,1175],

[430,477,705, 863,961,  991,1003,1121,1190,1236],
[524,611,793, 868,1027,  1111,1112,1123,1252,1253]
]
430

row:10 col:10
=============
low_x:0 low_y:0 high_x:9 high_y:9
mid_x:4 mid_y:4
=============
low_x:0 low_y:0 high_x:4 high_y:4
mid_x:2 mid_y:2
=============
low_x:0 low_y:3 high_x:2 high_y:4
is small
=============
low_x:3 low_y:0 high_x:4 high_y:2
is small
=============
low_x:0 low_y:5 high_x:4 high_y:9
mid_x:2 mid_y:7
=============
low_x:0 low_y:5 high_x:2 high_y:7
is small
=============
low_x:0 low_y:8 high_x:2 high_y:9
is small
=============
low_x:5 low_y:0 high_x:9 high_y:4
mid_x:7 mid_y:2
=============
low_x:5 low_y:0 high_x:7 high_y:2
is small