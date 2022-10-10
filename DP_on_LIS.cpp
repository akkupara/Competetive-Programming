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



class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>> &dp)
    {
        if(ind == n)//if it goes out of bound
            return 0;
        
        if(dp[ind][prev_ind+1] != -1)
            return dp[ind][prev_ind+1];
        int len = 0 + f(ind+1, prev_ind, nums, n, dp);//not pick case
        //since we dont pick, we move to the next index and unchanging the position of prev_ind since we are not picking it up
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])//prev = -1, implies that it doesnt have a previous element
        {
            len = max(len, 1 + f(ind+1, ind, nums, n, dp));//since we pick it, we move both ind and prev-ind by 1 towards right, where the prev_ind becomes ind and ind becomes ind+1
            
        }
            
        return dp[ind][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));//to represent ind = -1, we cannot use arrays, since they start from 0 index, so we use n+1 for prev_ind
        return f(0, -1, nums, n, dp);
    }
};
