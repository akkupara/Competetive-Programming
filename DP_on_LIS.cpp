1.) Longest Increasing Subsequence

--> Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1



Recursive solution:


class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, int n)
    {
        if(ind == n)//base case
            return 0;
        
        //not take
        int len = 0 + f(ind+1, prev, nums, n);//when u nottake, only move ind, keeping prev at the same position
        
        if(prev == -1 || nums[prev] <= nums[ind])
            len = max(len, 1 + f(ind+1, ind, nums, n));//when u take, move both the index
       
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        return f(0, -1, nums, n);
        
    }
};




Memoization:

--> since there is -1 in prev_index, we do a coordinate shift of 1 
--> declare a dp[N][N+1]
                (0->n-1)(-1 -> n-1)
                           changed to (0->n)
    
    
    class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, int n, vector<vector<int>> &dp)
    {
        if(ind == n)//base case
            return 0;
        
        if(dp[ind][prev+1] != -1)//1 coordinate shift
            return dp[ind][prev+1];
        //not take
        int len = 0 + f(ind+1, prev, nums, n, dp);//when u nottake, only move ind, keeping prev at the same position
        
        if(prev == -1 || nums[prev] < nums[ind])
            len = max(len, 1 + f(ind+1, ind, nums, n, dp));//when u take, move both the index
       
        return dp[ind][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        
        return f(0, -1, nums, n, dp);
        
    }
};




Tabulation code:


class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, int n, vector<vector<int>> &dp)
    {
        if(ind == n)//base case
            return 0;
        
        if(dp[ind][prev+1] != -1)//1 coordinate shift
            return dp[ind][prev+1];
        //not take
        int len = 0 + f(ind+1, prev, nums, n, dp);//when u nottake, only move ind, keeping prev at the same position
        
        if(prev == -1 || nums[prev] < nums[ind])
            len = max(len, 1 + f(ind+1, ind, nums, n, dp));//when u take, move both the index
       
        return dp[ind][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind=n-1; ind >= 0; ind--)
        {
            for(int prev=ind-1; prev >= -1; prev--)
            {
                int len = 0 + dp[ind+1][prev+1];//when u nottake, only move ind, keeping prev at the same position
        
                if(prev == -1 || nums[prev] < nums[ind])
                    len = max(len, 1 + dp[ind+1][ind+1]);//when u take, move both the index

                 dp[ind][prev+1] = len;
            }
        }
        
        
        return dp[0][-1+1];
        
    }
};



Using Binary search:


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);//push the first guy
        
        for(int i=1; i < n; i++)
        {
            if(nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};


