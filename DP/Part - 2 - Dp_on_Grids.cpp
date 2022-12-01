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
