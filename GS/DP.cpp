1.) climbing stairs 


--> similar to fibonacci series

Recursion code:



class Solution {
public:
    int f(int ind)
    {
        if(ind == 0)
            return 1;
        if(ind == 1)
            return 1;
        
        
        int onejump = f(ind-1);
        int twojump = f(ind-2);
        
        return (onejump+twojump);
    }
    int climbStairs(int n) {
        return f(n);
        
    }
};






Memoized code:


class Solution {
public:
    int f(int ind, vector<int>&dp)
    {
        if(ind == 0)
            return 1;
        if(ind == 1)
            return 1;
        if(dp[ind] != -1)
            return dp[ind];
        
        int onejump = f(ind-1, dp);
        int twojump = f(ind-2, dp);
        
        return dp[ind] = (onejump+twojump);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
        
    }
};







Tabulated code:

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1; 
        dp[1] = 1;
        
        for(int ind = 2; ind <= n; ind++)
        {
            dp[ind] = dp[ind-1] + dp[ind-2];
        }
        return dp[n];
        
    }
};



Space Optimisation:


class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1; 
        int prev2 = 1;
        
        for(int ind = 2; ind <= n; ind++)
        {
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
        
    }
};
