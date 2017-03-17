class Solution {
public:
int direct[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int dfs_search(int i,int j,int row,int col,vector<vector<int> >&visited,vector<vector<int> > &lens,vector< vector<int> > &matrix){
    if(lens[i][j]) return lens[i][j];
    int ans = 1;
    for(int g = 0;g<4;g++){
        int x = i + direct[g][0], y = j + direct[g][1];
        if(x<row&&x>=0&&y<col&&y>=0 && !visited[x][y] && matrix[x][y]>matrix[i][j]){
            visited[x][y] = 1;
            ans = max(ans,dfs_search(x,y,row,col,visited,lens,matrix)+1);
            visited[x][y] = 0;
        }
    }
    lens[i][j] = ans;
    return ans;
}
int longestIncreasingPath(vector<vector<int> >& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int> > visited(row, vector<int>(col,0));
        vector<vector<int> > lens(row, vector<int>(col,0));
        int ans = -1;
        for(int i=0;i<row;i++)
            for(int j = 0;j<col;j++){
                visited[i][j] = 1;
                lens[i][j] = dfs_search(i,j,row,col,visited,lens,matrix);
                visited[i][j] = 0;
                ans = max(ans,lens[i][j]);
            }
        return ans;
    }
};