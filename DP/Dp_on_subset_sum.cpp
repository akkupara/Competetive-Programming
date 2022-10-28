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








