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




