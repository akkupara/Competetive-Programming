1.) Unique Paths

--> There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
--> The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
--> The robot can only move either down or right at any point in time.
  
Recurrence:

class Solution {
public:
    int f(int i, int j)
    {
        if(i==0 && j==0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        int up = f(i-1, j);
        int left = f(i, j-1);
        
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return f(m-1, n-1); 
    }
};





Memoization:

class Solution {
public:
    int f(int i, int j, vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = f(i-1, j, dp);
        int left = f(i, j-1, dp);
        
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp); 
    }
};




Tabulation:

class Solution {
public:
    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m, vector<int>(n, 0));
        int dp[m][n];
        
        for(int i=0; i < m; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else
                {
                    int left = 0;
                    int up = 0;
                    
                    if(i > 0)
                        up = dp[i-1][j];
                    
                    if(j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};




2.) Unique paths with obstacles

--> An obstacle and space are marked as 1 or 0 respectively in grid. 
--> A path that the robot takes cannot include any square that is an obstacle.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        
        for(int i=0; i < m; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if(i==0 && j==0)
                    dp[i][j] = 1;
                else
                {
                    int left = 0;
                    int up = 0;
                    
                    if(i > 0)
                        up = dp[i-1][j];
                    
                    if(j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};



3.) Minimum path sum

--> Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

--> You can only move either down or right at any point in time.
    

Recursion solution:

class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid)
    {
        if(i==0 && j==0)
            return grid[i][j];
        if(i < 0 || j < 0)
            return 1e9;
        
        int up = grid[i][j] + f(i-1, j, grid);
        int left = grid[i][j] + f(i, j-1, grid);
        
        return min(up, left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return f(n-1, m-1, grid);
    }
};




Tabulation:


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                        up = up + dp[i-1][j];
                    else
                        up = up + 1e9;
                    
                    int left = grid[i][j];
                    if(j>0)
                        left = left + dp[i][j-1];
                    else
                        left = 1e9;
                    
                    dp[i][j] = min(left, up);
                
                }
            }
        }
        return dp[n-1][m-1];
    }
};



4.) Triangle


--> Given a triangle array, return the minimum path sum from top to bottom
--> Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 
     
     
     
     
     
Recursive solution:

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int n)
    {
        if(i == n-1)
            return triangle[n-1][j];
        
        int down = triangle[i][j] + f(i+1, j, triangle, n);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, n);
        
        return min(down, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return f(0, 0, triangle, n);
        
    }
};





Memoization solution:

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp)
    {
        if(i == n-1)
            return triangle[n-1][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int down = triangle[i][j] + f(i+1, j, triangle, n, dp);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, n, dp);
        
        return dp[i][j] = min(down, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //int m = triangle[0].size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return f(0, 0, triangle, n, dp);
        
    }
};



Tabulation:


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //int m = triangle[0].size();
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int j=0; j < n; j++)
            dp[n-1][j] = triangle[n-1][j];
        
        for(int i=n-2; i >= 0; i--)
        {
            for(int j=i; j >=0; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, dg);
            }
        }
        return dp[0][0];
    }
};
