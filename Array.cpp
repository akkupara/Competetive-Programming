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





2.) Pascal's triangle
 
 
Given an integer numRows, return the full pascal trinagle till with numRows rows


In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:

Input: numRows = 5
Output:  [1]
        [1,1]
       [1,2,1]
      [1,3,3,1]
     [1,4,6,4,1]


TC = 0(N*N) and SC = 0(N*N)
 
 
 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for(int i=0;i < numRows; i++)
        {
            r[i].resize(i+1);//each iteration we increase the size of the triangle
            r[i][0] = r[i][i] = 1;//we initialise the first and the last column to 0
            
            for(int j=1; j < i; j++)
            {
                r[i][j] = r[i-1][j-1] + r[i-1][j];// 
            }
        }
        return r;
    }
};




3.) Next Permutation


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k,l;
        for(k=n-2; k >= 0; k--)//used to find the index which has value juz greater than the last index
        {
            if(nums[k] < nums[k+1])   //given the array 1 3 5 4 2 traverse from the end, find which element is juz greater than 2, here it is 3, 
                //so ind1 = 1(index no)
                break;//ind1
        }
        if(k < 0)//if there is no break point simply reverse it
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(l=n-1; l> k ;l--)
            {
                if(nums[l] > nums[k])// with respect to ind1, check which is the next element that is juz greater than 3, which is 4
                    break;//ind2 point to index 3
            }
            swap(nums[k], nums[l]);//swap ind1 with and ind2
        
        //then reverse(int1+1, last)
        
        reverse(nums.begin()+k+1, nums.end());
        }
        
        
        
        
        
    }
};

