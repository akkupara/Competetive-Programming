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


