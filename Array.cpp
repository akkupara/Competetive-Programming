1.) Set Matrix to zero

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1]
                 [1,0,1]
                 [1,1,1]]
Output: [[1,0,1]
         [0,0,0]
         [1,0,1]]
         


Example 2:


Input: matrix = [[0,1,2,0]
                 [3,4,5,2]
                 [1,3,1,5]]
Output: [[0,0,0,0]
         [0,4,5,0]
         [0,3,1,0]]
 


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //we use the dummy arrays as the 0th row and col of the matrix
        // arr[0][0] is common to both row 0 and column 0
        //so while encountering 0, we update col0 and not arr[0][0] for columsn
        //for row updation we use arr[0][0]
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        
        for(int i=0; i < rows; i++)
        {
            //we check the value of the 0th column and ith row, if zero, we make col0 = 0
            if(matrix[i][0] == 0)
                col0 = 0;
            
            for(int j=1; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;//if any element is 0, we make 0th row and column 0
            }
            
        }
        
        
        
        for(int i=rows-1; i >= 0; i--)
        {
            for(int j=cols-1; j >= 1; j--)//till index 1, since for 0th column, we maintain col0 variable
            {
                if(matrix[i][0] == 0|| matrix[0][j] == 0)//if any those dummy arrays are marked as 0, make that indexes i, j as 0
                    matrix[i][j] = 0;
            }
            if(col0 == 0)
                matrix[i][0] = 0;//col0 = 0 means oth col is set to zero
            
        }
        
        
    }
};





