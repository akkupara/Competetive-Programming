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



3.) Partition Set Into 2 Subsets With Min Absolute Sum Diff 
  
  
  
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




7.) Coin change


--> You are given an integer array coins representing coins of different denominations 
--> an integer amount representing a total amount of money
--> Return the fewest number of coins that you need to make up that amount
--> If that amount of money cannot be made up by any combination of the coins, return -1
	

	
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
	
	
	
Recursive code:


class Solution {
public:
    int f(int ind, vector<int>& coins, int amount)
    {
        if(ind == 0)
        {
            if(amount % coins[ind] == 0)
                return amount / coins[ind];
            else
                return 1e9;
        }
        int nontake = 0 + f(ind-1, coins, amount);
        int take = INT_MAX;
        if(coins[ind] <= amount)
            take = 1 + f(ind, coins, amount-coins[ind]);//you stay at that index itself
        
        return min(take, nontake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n-1, coins, amount);
        if(ans >= 1e9)
            return -1;
        return ans;
        
    }
};



Memoized code:


class Solution {
public:
    int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(amount % coins[ind] == 0)
                return amount / coins[ind];
            else
                return 1e9;
        }
        
        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        
        int nontake = 0 + f(ind-1, coins, amount, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount)
            take = 1 + f(ind, coins, amount-coins[ind], dp);//you stay at that index itself since you can take that element till the if condition becomes false
        
        return dp[ind][amount] = min(take, nontake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
            
        int ans = f(n-1, coins, amount, dp);
        if(ans >= 1e9)
            return -1;
        return ans;
        
    }
};




Tabulation code:



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int T=0; T <= amount; T++)
        {
            if(T % coins[0] == 0)
                dp[0][T] = T / coins[0];
            else
                dp[0][T] = 1e9;
        }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int T=0; T <= amount; T++)
            {
                int nontake = 0 + dp[ind-1][T];
                int take = INT_MAX;
                if(coins[ind] <= T)
                    take = 1 + dp[ind][T-coins[ind]];
                
                dp[ind][T] = min(take, nontake);
            }
        }
           
        int ans = dp[n-1][amount];
        if(ans >= 1e9)
            return -1;
        return ans;
        
    }
};





8.) Target sum

--> You are given an integer array nums and an integer target.
--> You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer
in nums and then concatenate all the integers.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

	
	
--> this is similar/same to count partitions with given difference
--> same code where there is change in base case, the difference/target becomes (totsum-target)/2



class Solution {
public:
    int f(int ind, int target, vector<int>& nums, vector<vector<int>> &dp)
    {
        
        if(ind == 0)
        {
            if(nums[0] == 0 && target == 0)//later check out why cuz i have some doubt
                return 2;//there are 2 possibilites, either take/nontake
            
            if(target == 0 || target == nums[0])
                return 1;//see the video once again
            
            return 0;
        }
        
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int nontake = f(ind-1, target, nums, dp);
        int take = 0;
        
        if(nums[ind] <= target)
            take = f(ind-1, target-nums[ind], nums, dp);
        
        return dp[ind][target] = take + nontake;
    }
    
    int findWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return f(n-1, target, nums, dp);
    }
        
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i < n; i++)
            totsum += nums[i];
        
        if(totsum-target < 0 || (totsum - target) % 2)
            return false;
        
        return findWays(nums, (totsum-target)/2);
        
    }
        
};





9.) Coin change II

--> Subtle changes: In the first qs, we are supposed to return the fewest no of coins that we need to need to make up the amount, 
we calculate min(take, nontake) and add 1 to take case and initially keep take as INT_MAX.
	
--> In this qs, we return the no of combinations that make up the amount, here we calculate take+nontake, and we dont add 1 to the take case
	and keep take as 0 initially.
	
--> And in 1st qs, it is finite supply, whereas, in this qs, it is infinite supply

	
	
Recursive solution:


class Solution {
public:
    int f(int ind, vector<int>& coins, int amount)
    {
        if(ind == 0)
            return (amount % coins[0] == 0);
        
        int nontake = 0 + f(ind-1, coins, amount);
        int take = 0;
        if(coins[ind] <= amount)
            take = f(ind, coins, amount-coins[ind]);//you stay at that index itself
        
        return (take + nontake);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return f(n-1, coins, amount);
        
    }
};






Memoized solution:





class Solution {
public:
    int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
        if(ind == 0)
            return (amount % coins[0] == 0);
        
        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        
        int nontake = 0 + f(ind-1, coins, amount, dp);
        int take = 0;
        if(coins[ind] <= amount)
            take = f(ind, coins, amount-coins[ind], dp);//you stay at that index itself
        
        return dp[ind][amount] = (take + nontake);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return f(n-1, coins, amount, dp);
        
    }
};





Tabulated code:




class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        
        for(int t=0; t <= amount; t++)
        {
            dp[0][t] = (t % coins[0] == 0);//base case
        }
        
        for(int ind=1; ind < n; ind++)
        {
            for(int t = 0; t <= amount; t++)
            {
                int nontake = 0 + dp[ind-1][t];
                int take = 0;
                if(coins[ind] <= t)
                    take = dp[ind][t-coins[ind]];
                
                dp[ind][t] = take + nontake;
            }
        }
        return dp[n-1][amount];
        
    }
};



space optimised:



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        
        for(int t=0; t <= amount; t++)
        {
            prev[t] = (t % coins[0] == 0);//base case
        }
        
        for(int ind=1; ind < n; ind++)
        {
            for(int t = 0; t <= amount; t++)
            {
                int nontake = 0 + prev[t];
                int take = 0;
                if(coins[ind] <= t)
                    take = cur[t-coins[ind]];
                
                cur[t] = take + nontake;
            }
            prev = cur;
        }
        return prev[amount];
        
    }
};







10.) Unbounded knapsack

--> same as 0/1 knapsack where duplicates or infinite supply is allowed

Recursive code:


class Solution{
public:
    int f(int ind, int W, int val[], int wt[])
    {
        if(ind == 0)
            return ((int)(W / wt[0]))*val[0];
        
        int nontake = 0 + f(ind-1, W, val, wt);
        int take = 0;
        if(wt[ind] <= W)
            take = val[ind] + f(ind, W-wt[ind], val, wt);
        return max(take, nontake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return f(N-1, W, val, wt);
    }
};




Memoized code:


class Solution{
public:
    int f(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if(ind == 0)
            return ((int)(W / wt[0]))*val[0];
        
        if(dp[ind][W] != -1)
        return dp[ind][W];
        
        
        int nontake = 0 + f(ind-1, W, val, wt, dp);
        int take = 0;
        if(wt[ind] <= W)
            take = val[ind] + f(ind, W-wt[ind], val, wt, dp);
            
            
        return dp[ind][W] = max(take, nontake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W+1, -1));
        return f(N-1, W, val, wt, dp);
    }
};




Tabulated code:


class Solution{
public:
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W+1, 0));
        for(int w = 0; w <= W; w++)
        {
            dp[0][w] = (int(w/wt[0]))*val[0];
        }
        
        for(int ind = 1; ind < N; ind++)
        {
            for(int w = 0; w <= W; w++)
            {
                int nontake = 0 + dp[ind-1][w];
                int take = 0;
                if(wt[ind] <= w)
                    take = val[ind] + dp[ind][w-wt[ind]];
                
                dp[ind][w] = max(take, nontake);
            }
        }
        
        return dp[N-1][W];
    }
};





Space optimised code:


class Solution{
public:
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        
        vector<int> prev(W+1, 0), cur(W+1, 0);
        
        for(int w = 0; w <= W; w++)
        {
            prev[w] = (int(w/wt[0]))*val[0];
        }
        
        for(int ind = 1; ind < N; ind++)
        {
            for(int w = 0; w <= W; w++)
            {
                int nontake = 0 + prev[w];
                int take = 0;
                if(wt[ind] <= w)
                    take = val[ind] + cur[w-wt[ind]];
                
                cur[w] = max(take, nontake);
            }
            prev = cur;
        }
        
        return prev[W];
    }
};






11. Rod Cutting


--> Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. 
--> Determine the maximum value obtainable by cutting up the rod and selling the pieces.
--> similar to unbounded knapsack if approached differently, other way of looking at this qs is collect rod length to make N and maximise the amount


Recursive code:

class Solution{
  public:
    int f(int ind, int N, int price[])
    {
        if(ind == 0)
            return N*price[0];//see the video once again
        
        int nontake = 0 + f(ind-1, N, price);
        int take = INT_MIN;
        
        int rod_length = ind+1;
        if(rod_length <= N)
            take = price[ind] + f(ind, N-rod_length, price);
            
        return max(take, nontake);
    }
    int cutRod(int price[], int n) {
        return f(n-1, n, price);
    }
};




Memoized code:


class Solution{
  public:
    int f(int ind, int N, int price[], vector<vector<int>> &dp)
    {
        if(ind == 0)
            return N*price[0];//see the video once again
        
        
        if(dp[ind][N] != -1)
            return dp[ind][N];
            
            
        int nontake = 0 + f(ind-1, N, price, dp);
        int take = INT_MIN;
        
        int rod_length = ind+1;
        if(rod_length <= N)
            take = price[ind] + f(ind, N-rod_length, price, dp);
            
        return dp[ind][N] = max(take, nontake);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return f(n-1, n, price, dp);
    }
};




Tabulation code:


class Solution{
  public:
    int cutRod(int price[], int N) {
        vector<vector<int>> dp(N, vector<int> (N+1, 0));
        
        for(int n = 0; n <= N; n++)
            dp[0][n] = n * price[0];//base cases
            
            
        for(int ind=1; ind < N; ind++)
        {
            for(int n = 0; n <= N; n++)
            {
                int nontake = 0 + dp[ind-1][n];
                int take = INT_MIN;
                
                int rod_length = ind+1;
                if(rod_length <= n)
                    take = price[ind] + dp[ind][n-rod_length];
                    
                dp[ind][n] = max(take, nontake);
            }
        }
        return dp[N-1][N];
    }
};




Space optimised code:


class Solution{
  public:
    int cutRod(int price[], int N) {
       
        vector<int> prev(N+1, 0), cur(N+1, 0);
        
        for(int n = 0; n <= N; n++)
            prev[n] = n * price[0];//base cases
            
            
        for(int ind=1; ind < N; ind++)
        {
            for(int n = 0; n <= N; n++)
            {
                int nontake = 0 + prev[n];
                int take = INT_MIN;
                
                int rod_length = ind+1;
                if(rod_length <= n)
                    take = price[ind] + cur[n-rod_length];
                    
                cur[n] = max(take, nontake);
            }
            prev = cur;
        }
        return prev[N];
    }
};



