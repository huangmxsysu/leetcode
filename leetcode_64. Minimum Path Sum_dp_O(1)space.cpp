class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size() , n = grid[0].size();
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            grid[i][0] = sum + grid[i][0];
            sum = grid[i][0];
        }
        sum = 0;
        for (int j = 0; j < n; ++j) {
            grid[0][j] = sum + grid[0][j];
            sum = grid[0][j];
        }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) 
                grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
        return grid[m-1][n-1];
    }
};