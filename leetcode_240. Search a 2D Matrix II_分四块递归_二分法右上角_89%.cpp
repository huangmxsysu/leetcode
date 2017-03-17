class Solution {  
public:  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {  
            int rows = matrix.size();  
        if (rows<=0)  
            return false;  
        int cols = matrix[0].size();  
        int i=0, j=cols-1;  
        while (i<rows && j>=0)  
        {  
            int x = matrix[i][j];  
            if (x == target)  
            {  
                return true;  
            }else if (x >target)  
            {  
                j--;  
            }else{  
                i++;  
            }  
        }  
        return false;  
    }  
};  