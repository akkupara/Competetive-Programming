1.) Frog Jump

--> Need to look into it again
--> It has two solutions: one is the recusive way which is way long expensive
--> The other involves DP and the more better approach is using tabulation


Recursive solution and also using DP:


int f(int ind, vector<int> &heights, vector<int> &dp)
{
    if(ind == 0)
        return 0;
    if(dp[ind] != -1)
        return dp[ind];
    
    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;//right recursion will work only if n > 1
    
    if(ind > 1)
        right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    
    
    return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}


Using Tabulation:

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);//initialize the dp array to zero and the size is n
    dp[0] = 0;
    
    for(int i=1; i < n; i++)
    {
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        
        if(i > 1)
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}




2.) Jump game - https://www.youtube.com/watch?v=muDPTDrpS28

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
  
  
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


  Pretty easy solution
  
  class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        
        for(int i=0; i < n; i++)
        {
            if(reachable < i)//when i becomes more than reachable, then return false, meaninng it has encountered a 0
                return false;
            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }
};



3.) Max Element without adjacents

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
    
    
    

--> RECURSIVE SOLUTION TAKES MUCH LONGER EXECUTION TIME WHICH CAN BE FURTHER OPTIMISED


--> Recursive solution:

class Solution{
public:	//RECURSIVE SOLUTION WHICH TAKES LONG EXECUTION TIME BECAUSE OF OVERLAPPING SUB-PROBLEMS
    int f(int ind, int *arr)
    {
        if(ind == 0)
            return arr[ind];//if index is equal to 0, then return arr[ind], becuz we r going to pick it up
        if(ind < 0)
            return 0;//if index goes less than 0, then return 0
            
        int pick = arr[ind] + f(ind-2, arr);//if you pick it then add that index value with element that is non-adjacent
        int notpick = 0 + f(ind-1, arr);//if you dont pick it, then dont add that index but add only the adjacent element
        
        return max(pick, notpick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    return f(n-1, arr);//the recursive function which will find the max sum, where we pass index till which the iteration should be done
	}
};


--> we can use a dp array to space optimise it which can avoid TLE

DP SOLUTION:


class Solution{
public:	//USING DP TO SPACE OPTIMISE TO SOME EXTENT
    int f(int ind, int *arr, vector<int> &dp)
    {
        if(ind == 0)
            return arr[ind];//if index is equal to 0, then return arr[ind], becuz we r going to pick it up
        if(ind < 0)
            return 0;//if index goes less than 0, then return 0
        
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int pick = arr[ind] + f(ind-2, arr, dp);//if you pick it then add that index value with element that is non-adjacent
        int notpick = 0 + f(ind-1, arr, dp);//if you dont pick it, then dont add that index but add only the adjacent element
        
        return dp[ind] = max(pick, notpick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    return f(n-1, arr, dp);//the recursive function which will find the max sum, where we pass index till which the iteration should be done
	}
};



using tabulation the Tc = O(N) and SC = O(N) which can further be space optimised

TABULATION:

class Solution{
public:	//USING tabulation 
    
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    dp[0] = 0;
	    int neg = 0;//if the index goes negative, we return 0
	    
	    
	    for(int i=1; i < n; i++)
	    {
	        int take = arr[i];
	        if(i > 1)
	            take += dp[i-2];//this is to ensure that index i-2 doesnt go less than zero
	        
	        int nontake = 0 + dp[i-1];
	        
	        dp[i] = max(take, nontake);
	    }
	    return dp[n-1];//the recursive function which will find the max sum, where we pass index till which the iteration should be done
	}
};





Tabulation with space optimisation: TC = O(N) & SC = O(1)
    
    
    
class Solution{
public:	//USING tabulation with space optimisation
    
int findMaxSum(int *arr, int n) {
    int prev = arr[0];
    int prev2 = 0;
    
    for(int i=1; i < n; i++)
    {
        int take = arr[i];
        if(i > 1)
            take = take + prev2;
            
        int nontake = 0 + prev;
        
        int curi = max(take, nontake);
        
        prev2 = prev;
        prev = curi;
        
    }
    return prev;
}
};





4.) House robber

--> same as the above qs if the houses are in a straight line
--> Slight change in the logic if the houses are in a circle, since there we should not pick first and last, since they are together(Adjacent)
    
if the houses are in a stright line


int prev = arr[0];
    int prev2 = 0;
    
    for(int i=1; i < n; i++)
    {
        int take = arr[i];
        if(i > 1)
            take = take + prev2;
            
        int nontake = 0 + prev;
        
        int curi = max(take, nontake);
        
        prev2 = prev;
        prev = curi;
        
    }
    return prev;



if the houses are in a circle


class Solution {
public:
    long long int max_Non_Adjacent_Sum(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
    
    for(int i=1; i < n; i++)
    {
        int take = nums[i];
        if(i > 1)
            take = take + prev2;
            
        int nontake = 0 + prev;
        
        int curi = max(take, nontake);
        
        prev2 = prev;
        prev = curi;
        
    }
    return prev;
}
    
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(nums.size() == 1)//if there is only one house
            return nums[0];//return the zero index value
        
        vector<int> temp1, temp2;
        for(int i=0; i < n; i++)
        {
            if(i != 0)
                temp1.push_back(nums[i]);//we push all the values of nums vector into temp1 except for the first index
            
            if(i != n-1)
                temp2.push_back(nums[i]);//we push all the values of nums vector into temp1 except for the last index
            
        }
        
        int first = max_Non_Adjacent_Sum(temp1);//we are leaving everthing except first element
        int last = max_Non_Adjacent_Sum(temp2);//we are leaving everthing except last element
        
        return max(first, last);//and returning the max of both the elements
        
    }
};



5.) Unique paths

Example 1:


Input: m = 3, n = 7
Output: 28
    
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
    
    
--> Can be solved using combinations



class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = (m-1) + (n-1);//total no of paths availabel
        int r = m-1;//we are going to place N in r ways
        
        double res = 1;
        
        for(int i=1; i <= r; i++)
        {
            res = res*(N-r+i)/i;
        }
        return int(res);
        
    }
};


6.) Unique path with obstacles


--> Same as the above question but contains some obstacles
--> same code but if we reach the obstacle, juz return zero
--> need to solve in much more optimised way


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (obstacleGrid[i - 1][j - 1] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
        return dp[m][n];
    } 
};




7.) Minimum path sum


--> Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Input: grid = [[1,3,1]
	       [1,5,1]
	       [4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
	
	
	
IMPORTANT QS


Using memoization:

class Solution {
public://using memoization
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)//if both i and j are zero then add that to the min path
            return grid[i][j];
        
        if(i < 0 || j < 0)//if it goes out of index, then add some very large number
            return 1e9;
        
        if(dp[i][j] != -1) //if it is already present, then return the stored answer
            return dp[i][j];
        
        int up = grid[i][j] + f(i-1, j, grid, dp);//add that path element and move up
        int left = grid[i][j] + f(i, j-1, grid, dp);//add that path element and move left
        
        return dp[i][j] = min(up, left);//return the minimum since we want the minimum path length
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n-1, m-1, grid, dp);
        
    }
};



Using Tabulation and space optimisation


class Solution {
public://using tabulation with space optimisation
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<int> prev(m, 0);
        vector<int> cur(m, 0);
        
        int i, j;
        for(i=0; i< n; i++)
            for(j=0; j < m; j++)
            {
                if(i == 0 && j == 0)
                    cur[j] = grid[i][j];
                
                
                else
                {
                    int up = grid[i][j];
                    if(i > 0)
                        up = up + prev[j];//add that path element and move up
                    else
                        up = up + 1e9;

                    int left = grid[i][j];
                    if(j > 0)
                        left = left + cur[j-1];//add that path element and move left
                    else
                        left = left + 1e9;

                    cur[j] = min(up, left);
                }
                prev = cur;
            }
        return prev[m-1];
    }
};




8.) Triangle

--> Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
	
	
	
	
Memoization code


class Solution {
public://memoization code
    int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp) {
		if(i == n - 1)
			return triangle[i][j];
		if(dp[i][j] != -1)
			return dp[i][j];
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
		return dp[i][j] = min(bottom, bottom_right);
	}
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		return solve(0, 0, n, triangle, dp);
    }
};



Tabulation with space optimisation


class Solution {
public://space otimisation with tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);
        
        for(int i=n-1; i >= 0; i--)
        {
            vector<int> cur(n, 0);
            for(int j=i; j >= 0; j--)
            {
                if(i == n-1)
                    cur[j] = triangle[i][j];
                else
                {
                    int down = triangle[i][j] + front[j];
                    int dg = triangle[i][j] + front[j+1];
                    cur[j] = min(down, dg);
                }
            }
            front = cur;
        }
         
      return front[0]; 
    }
    
};




9.) Minimum Falling path sum

--> Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
--> Example 1:


Input: matrix = [[2,1,3]
		 [6,5,4]
		 [7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
	
	
	
	
Memoization code:


class Solution {
public://Memoization code
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp)
    {
        if(j < 0 || j >= matrix[0].size())
            return 1e8;//if in column it goes out of range, the return some very negative value
        
        
        if(i == 0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);
        
        return dp[i][j] = min(up, min(ld, rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        int min = 1e8;
        
        for(int j=0; j < m; j++)
        {
            min = min(maxi, f(n-1, j ,matrix, dp));
        }
        return min;
        
    }
};




Tabulation code:

class Solution {
public://tabulation code

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int j=0; j < m; j++)
        {
            dp[0][j] = matrix[0][j];//filling initially with the first row from the matrix into the dp table
        }
        
        for(int i=1; i < n; i++)
            for(int j=0; j < m; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                
                int ld = matrix[i][j];
                    if(j-1 >= 0)
                        ld = ld + dp[i-1][j-1];
                    else
                        ld = ld + 1e9;
                
                
                int rd = matrix[i][j];
                    if(j+1 < m)
                        rd = rd + dp[i-1][j+1];
                    else
                        rd = rd + 1e9;
                
                dp[i][j] = min(up, min(ld, rd));
            }
        
        
        int mini = 1e8;
        
        for(int j=0; j < m; j++)
        {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
        
    }
};




Tabulation with space optimisation:

class Solution {
public://tabulation with space optimisation code

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> prev(m, 0), cur(m, 0);
        for(int j=0; j < m; j++)
        {
            prev[j] = matrix[0][j];//filling initially with the first row from the matrix into the dp table
        }
        
        for(int i=1; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                int up = matrix[i][j] + prev[j];
                
                int ld = matrix[i][j];
                    if(j-1 >= 0)
                        ld = ld + prev[j-1];
                    else
                        ld = ld + 1e9;
                
                
                int rd = matrix[i][j];
                    if(j+1 < m)
                        rd = rd + prev[j+1];
                    else
                        rd = rd + 1e9;
                
                cur[j] = min(up, min(ld, rd));
            }
            prev = cur;
        }
        
        
        int mini = 1e8;
        
        for(int j=0; j < m; j++)
        {
            mini = min(mini, prev[j]);
        }
        return mini;
        
    }
};


