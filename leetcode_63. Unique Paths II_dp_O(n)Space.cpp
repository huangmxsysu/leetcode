class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> temp(m + 1, 0);
        temp[m-1] = 1;
        for (int j = n - 1; j >= 0; j--) {
            for (int i = m - 1; i >= 0; i--) {
                if (obstacleGrid[i][j]) temp[i] = 0;
                else temp[i] += temp[i+1];
            }
        }
        return temp[0];
    }
};
