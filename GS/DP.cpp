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



2.) Jump game


--> You are given an integer array nums. You are initially positioned at the arrays first index, 
and each element in the array represents your maximum jump length at that position.

--> Return true if you can reach the last index, or false otherwise.
    
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
    
    
    
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    
    
https://www.youtube.com/watch?v=muDPTDrpS28


This is a classy greedy solution


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        
        for(int i=0; i < n; i++)
        {
            if(reachable < i)
                return false;
            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }
};





3.) Jump game II


--> You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

--> Each element nums[i] represents the maximum length of a forward jump from index i. In other words, 
if you are at nums[i], you can jump to any nums[i + j] 


Greedy solution:

--> we are going to have two pointer l and r, we run the while loop till  r < n-1, and move the two pointer by forming the windows and 
    updating the result each time, and move l and r each iteration 
    
    
 class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int l = 0, r = 0;//two pointers
        
        int farthest = 0;
        
        while(r < n-1)
        {
            for(int i=l; i <= r; i++)
            {
                farthest = max(farthest, i+nums[i]);//it hold the max reachable distance from that index
                
            }
            l = r + 1;//move the window
            r = farthest;//move the right pointer
            
            res = res+1;//we increment the counter which represents the min no of jumps
            
        }
        return res;
        
        
    }
};



4.) Jump game III (can be solved using BFS) Recursive solution

TC = O(N) and Sc = O(N) using extra space



--> Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
    When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
    
    
--> Notice that you can not jump outside of the array at any time.
    

    
bases case - return false
    
1.) if that node is already visited
2.) if jump goes out of bound

class Solution {
public:
    unordered_set<int> visited; 
    
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        
        if(visited.count(start) == 1 || start < 0 || start >= n)
            return false;//base cases
        
        if(nums[start] == 0)//if 0 is found
            return true;
        
        //otherwise mark it visited
        visited.insert(start);//insert that index into set
        
        return (canReach(nums, start-nums[start]) || canReach(nums, start+nums[start]));
        
    }
};




5.) 



