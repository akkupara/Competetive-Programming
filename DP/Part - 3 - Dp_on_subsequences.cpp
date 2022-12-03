1.) subset sum equal to target

--> Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
  
  
  --> Another approach using recursion which gives TLE:

class Solution{   
public:
    bool f(int ind, int target, vector<int> &arr)
    {
        if(target == 0)
            return true;//if at any point the target becomes zero, return true
            //because we got subsequence which made the target zero
            
        if(ind == 0)
            return (arr[0] == target);//if we reach the first index, if that first index element is 
            //equal to the target, we return true else false
        
        bool nottake = f(ind-1, target, arr);//if we dont pick it we juz move back to the prev index
        bool take = false;//intially false
        
        if(target >= arr[ind])//we pick the element only if it is less than the target
            take = f(ind-1, target-arr[ind], arr);
            
        return take | nottake;
        
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return f(n-1, sum, arr);//the index is n-1, target is sum
        

    }
};




--> using memoization and dp table


class Solution{   
public://using memoization and dp
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;//if at any point the target becomes zero, return true
            //because we got subsequence which made the target zero
            
        if(ind == 0)
            return (arr[0] == target);//if we reach the first index, if that first index element is 
            //equal to the target, we return true else false
            
        if(dp[ind][target] != -1)
            return dp[ind][target];
            
        bool nottake = f(ind-1, target, arr, dp);//if we dont pick it we juz move back to the prev index
        bool take = false;//intially false
        
        if(target >= arr[ind])//we pick the element only if it is less than the target
            take = f(ind-1, target-arr[ind], arr, dp);
            
        return dp[ind][target] = take | nottake;
        
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(n-1, sum, arr, dp);//the index is n-1, target is sum
    
    }
};


--> using tabulation code: TC = o(N * target) and SC = O(N * target) + O(N) ASS


class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
        
        for(int i=0; i < n; i++)
            dp[i][0] = true;
    
        dp[0][arr[0]] = true;
        
        for(int ind=1; ind < n; ind++)
        {
            for(int target=1; target <= sum; target++)
            {
                bool not_take = dp[ind-1][target];
                bool take = false;
                if(target >= arr[ind])
                    take = dp[ind-1][target-arr[ind]];
                
                dp[ind][target] = take || not_take;
            }
        }
        return dp[n-1][sum];
    }
};



tabulation with space optimisation: TC = o(N * target) and SC = O(target)
  
  
  class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n = arr.size();
        vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        
        //we dont need this instead we put this statement
        //for(int i=0; i < n; i++)
            //dp[i][0] = true;//
            
        prev[0]  = true;
    
        prev[arr[0]] = true;
        
        for(int ind=1; ind < n; ind++)
        {
            for(int target=1; target <= sum; target++)
            {
                bool not_take = prev[target];
                bool take = false;
                if(target >= arr[ind])
                    take = prev[target-arr[ind]];
                
                curr[target] = take || not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};




2.) Partition equal subset sum

--> same as the above qs
--> slight modification


Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
	
	
	

recususive solution: TC = O(2^N) and SC = O(N) ASS


class Solution{   
public:
    bool f(int ind, int target, vector<int> &nums)
    {
        if(target == 0)
            return true;//if at any point the target becomes zero, return true
            //because we got subsequence which made the target zero
            
        if(ind == 0)
            return (nums[0] == target);//if we reach the first index, if that first index element is 
            //equal to the target, we return true else false
        
        bool nottake = f(ind-1, target, nums);//if we dont pick it we juz move back to the prev index
        bool take = false;//intially false
        
        if(target >= nums[ind])//we pick the element only if it is less than the target
            take = f(ind-1, target-nums[ind], nums);
            
        return take | nottake;
        
    }
    
    bool canPartition(vector<int>nums){
        
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i < n; i++)
        {
            totsum = totsum + nums[i];
        }
        int target = totsum / 2;
        if(totsum % 2 == 1)
            return false;
        
        return f(n-1, target, nums);

    }
};



--> using memoization and dp table: TC = O(N * target) and SC = O(N * target) + o(N) ASS

class Solution{   
public:
    bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;//if at any point the target becomes zero, return true
            //because we got subsequence which made the target zero
            
        if(ind == 0)
            return (nums[0] == target);//if we reach the first index, if that first index element is 
            //equal to the target, we return true else false
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        bool nottake = f(ind-1, target, nums, dp);//if we dont pick it we juz move back to the prev index
        bool take = false;//intially false
        
        if(target >= nums[ind])//we pick the element only if it is less than the target
            take = f(ind-1, target-nums[ind], nums, dp);
            
        return dp[ind][target] = take | nottake;
        
    }
    
    bool canPartition(vector<int>nums){
        
        int n = nums.size();
        int totsum = 0;
        
        for(int i=0; i < n; i++)
        {
            totsum = totsum + nums[i];
        }
        int target = totsum / 2;
        vector<vector<int>> dp(n, vector<int>(totsum+1, -1));
        if(totsum % 2 == 1)
            return false;
        
        return f(n-1, target, nums, dp);

    }
};



--> using tabulation: TC = O(N * target) and SC = O(N * target)
  
  
  
class Solution{   
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
        
        for(int i=0; i < n; i++)
            dp[i][0] = true;
    
        dp[0][arr[0]] = true;
        
        for(int ind=1; ind < n; ind++)
        {
            for(int target=1; target <= sum; target++)
            {
                bool not_take = dp[ind-1][target];
                bool take = false;
                if(target >= arr[ind])
                    take = dp[ind-1][target-arr[ind]];
                
                dp[ind][target] = take || not_take;
            }
        }
        return dp[n-1][sum];
    }
    bool canPartition(vector<int>nums){
        
        int n = nums.size();
        int totsum = 0;
        
        for(int i=0; i < n; i++)
        {
            totsum = totsum + nums[i];
        }
        
        int tar = totsum / 2;
        
        if(totsum % 2 == 1)
            return false;
        
        else
            return isSubsetSum(nums, tar);

    }
};



Space optimisation:

class Solution{   
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        
        int n = arr.size();
        vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        
        //we dont need this instead we put this statement
        //for(int i=0; i < n; i++)
            //dp[i][0] = true;//
            
        prev[0]  = true;
    
        if(sum > arr[0])
            prev[arr[0]] = true;
        
        for(int ind=1; ind < n; ind++)
        {
            for(int target=1; target <= sum; target++)
            {
                bool not_take = prev[target];
                bool take = false;
                if(target >= arr[ind])
                    take = prev[target-arr[ind]];
                
                curr[target] = take || not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>nums){
        
        int n = nums.size();
        int totsum = 0;
        
        for(int i=0; i < n; i++)
        {
            totsum = totsum + nums[i];
        }
        if(totsum % 2 == 1)
            return false;
        
        int tar = totsum / 2;
        
        
        
        return isSubsetSum(nums, tar);

    }
};



3.) 
  
  
  
  class Solution {
public:
    int minimumDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i < n; i++)
            totsum = totsum + nums[i];
        
        int k = totsum;
        
        vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
        
        for(int i=0; i < n; i++)
            dp[i][0] = true;
        if(nums[0] <= k)
            dp[0][nums[0]] = true;
        
        for(int ind=1; ind < n; ind++)
        {
            for(int target=1; target <= k; target++)
            {
                bool not_take = dp[ind-1][target];
                bool take = false;
                if(target >= nums[ind])
                    take = dp[ind-1][target-nums[ind]];
                
                dp[ind][target] = take || not_take;
            }
        }
        
        
        int mini = 1e9;
        for(int s1=0; s1 <= totsum/2; s1++)
        {
            if(dp[n-1][s1] == 1)
            {
                
                mini = min(mini, abs((totsum - s1) - s1));//s2 = totsum-s1 and 
            }
        }
        return mini;
    }
};



4.) Count subsets with sum K / Perfect sum


--> Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.
--> input arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
        Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}



Recusion solution


class Solution{
	public:
	int f(int ind, int sum, int arr[])
	{
	    if(sum == 0)
	        return 1;
	    if(ind == 0)
	        return (arr[ind] == sum);
	    
	    int nonpick = f(ind-1, sum, arr);
	    int pick = 0;
	    if(arr[ind] <= sum)
	        pick = f(ind-1, sum-arr[ind], arr);
	        
	    return pick+nonpick;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        return f(n-1, sum, arr);
	}
};



recussive/ memoized solution in GFG


class Solution{
	public:
	int mod = 1e9+7;
	long f(int ind, int sum, int arr[], int n, vector<vector<long>> &dp)
	{
	    
	    if(ind == 0)
	    {  
	       if(sum==0 and arr[0]==0) return 2;
           if(sum==0 or sum==arr[0]) return 1;

           return 0;
	        
	    }
	        
	    if(dp[ind][sum] != -1)
	        return dp[ind][sum]%mod;
	        
	        
	    long nonpick = f(ind-1, sum, arr, n, dp)%mod;
	    long pick = 0;
	    if(arr[ind] <= sum)
	        pick = f(ind-1, sum-arr[ind], arr, n, dp)%mod;
	        
	    return dp[ind][sum] = (pick+nonpick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<long>> dp(n, vector<long> (sum+1, -1));
        return f(n-1, sum, arr, n, dp)%mod;
        
	}
};


6.) 0/1 Knapsack problem


--> given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
--> You cannot break an item, either pick the complete item or dont pick it (0-1 property).


class Solution
{
    public:
    int f(int ind, int W, int wt[], int val[], int n)
    {
        if(ind == 0)
        {
            if(wt[ind] <= W)
                return val[0];
            else
                return 0;
        }
        
        int nontake = 0 + f(ind-1, W, wt, val, n);
        int take = INT_MIN;
        if(wt[ind] <= W)
            take = val[ind] + f(ind-1, W-wt[ind], wt, val, n);
        
        return max(nontake, take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       return f(n-1, W, wt, val, n);
    }
};



Memoized solution:


class Solution
{
    public:
    int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(wt[ind] <= W)
                return val[0];
            else
                return 0;
        }
        
        if(dp[ind][W] != -1)
            return dp[ind][W];
        
        int nontake = 0 + f(ind-1, W, wt, val, dp);
        int take = INT_MIN;
        if(wt[ind] <= W)
            take = val[ind] + f(ind-1, W-wt[ind], wt, val, dp);
        
        return dp[ind][W] = max(nontake, take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int> (W+1, -1));
       return f(n-1, W, wt, val, dp);
    }
};



Tabulation solution:


class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int> (W+1, 0));
       for(int w=wt[0]; w <= W; w++)
       {
           dp[0][w] = val[0];//we can steal it
       }
       
       for(int ind=1; ind < n; ind++)
       {
           for(int w=0; w <= W; w++)
           {
               int nontake = 0 + dp[ind-1][w];
               int take = INT_MIN;
                if(wt[ind] <= w)
                    take = val[ind] + dp[ind-1][w-wt[ind]];
                    
                dp[ind][w] = max(nontake, take);
           }
       }
       return dp[n-1][W];
    }
};





