1.) DP on stocks:

-->You are given an array prices where prices[i] is the price of a given stock on the ith day.

-->You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
  
  
 Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
  
  
  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = INT_MIN;
        int n = prices.size();
        
        for(int i=0; i < n; i++)
        {
            mini = min(mini, prices[i]);//mini to keep track min value as we traverse thru the array
            int cost = prices[i] - mini;//subtract mini with each element of the array iteratively
            profit = max(profit, cost);//check which gives the largest value
        }
        return profit;
        
     
        
    }
};




2.) Best Time to Buy and Sell Stock II


--> On each day, you may decide to buy and/or sell the stock.
--> You can only hold at most one share of the stock at any time.
--> you cannot buy another stock before selling the stock you had.
--> However, you can buy it then immediately sell it on the same day.
  
  
Recursion solution:(gives TLE)

class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n)
    {
        int profit = 0;
        if(ind == n)//if the index goes out of bound, then return 0
            return 0;
        
        if(buy == 1)//suppose he has the liberty to buy, there are two choices, one is he can buy or he can not buy
        {
            int pick = -prices[ind] + f(ind+1, 0, prices, n);//if it is picked, then we move to the next index, where we cannnot buy, so buy = 0
            int nonpick = 0 + f(ind+1, 1, prices, n);//we dont pick, so we move to the next index and we can still buy so buy = 1
            
            profit = max(pick, nonpick);
        }
        else
        {
            int pick = prices[ind] + f(ind+1, 1, prices, n);//since we sell, amount on that added and then move to the next index, keeping buy=1, since we can buy anything as we have sold before
            
            int nonpick = 0 + f(ind+1, 0, prices, n);// since we didnt sell, we add 0 and move to the next index, keeping buy=0, since we cannot buy anything
            
            profit = max(pick, nonpick);
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        return f(0, 1, prices, n);
        
    }
};




memoization: TC = O(n*2) and SC = O(n*2) + O(n)(auxiliary space)


class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp)
    {
        int profit = 0;
        if(ind == n)//if the index goes out of bound, then return 0
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        if(buy == 1)//suppose he has the liberty to buy, there are two choices, one is he can buy or he can not buy
        {
            int pick = -prices[ind] + f(ind+1, 0, prices, n, dp);//if it is picked, then we move to the next index, where we cannnot buy, so buy = 0
            int nonpick = 0 + f(ind+1, 1, prices, n, dp);//we dont pick, so we move to the next index and we can still buy so buy = 1
            
            profit = max(pick, nonpick);
        }
        else
        {
            int pick = prices[ind] + f(ind+1, 1, prices, n, dp);//since we sell, amount on that added and then move to the next index, keeping buy=1, since we can buy anything as we have sold before
            
            int nonpick = 0 + f(ind+1, 0, prices, n, dp);// since we didnt sell, we add 0 and move to the next index, keeping buy=0, since we cannot buy anything
            
            profit = max(pick, nonpick);
        }
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));//creating a n*2 dp table, 2 since buy can be either 0/1
        
        return f(0, 1, prices, n, dp);
        
    }
};



Tabulation code: TC = O(n*2) and SC = O(n*2)
  
  
 class Solution {
public://tabulation code
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        int profit = 0;
        dp[n][0] = dp[n][1] = 0;//base case(for whole index n and when buy is 0/1)
        
        //for loops will be running from i-1 to 0
        for(int ind = n-1; ind >= 0; ind--)
            for(int buy = 0; buy <= 1; buy++)
                if(buy == 1)//suppose he has the liberty to buy, there are two choices, one is //he can buy or he can not buy
                {
                    int pick = -prices[ind] + dp[ind+1][0];//if it is picked, then we move to the next index, where we cannnot buy, so buy = 0
                    int nonpick = 0 + dp[ind+1][1];//we dont pick, so we move to the next index and we can still buy so buy = 1

                    profit = max(pick, nonpick);
                    dp[ind][buy] = profit;
                }
                else
                {
                    int pick = prices[ind] + dp[ind+1][1];//since we sell, amount on that added and then move to the next index, keeping buy=1, since we can buy anything as we have sold before

                    int nonpick = 0 + dp[ind+1][0];// since we didnt sell, we add 0 and move to the next index, keeping buy=0, since we cannot buy anything

                    profit = max(pick, nonpick);
                    dp[ind][buy] = profit;
                }
            
        
        return dp[0][1];//since tabulation is bottom up, we return the ans present at the top
    }
};




Tabulation with space optimisation:

class Solution {
public://tabulation with space optimisation code
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2, 0), cur(2, 0);//replace dp[n] with ahead and curr with dp[ind+1]
        
        int profit = 0;
        prev[0] = prev[1] = 0;//base case(for whole index n and when buy is 0/1)
        
        //for loops will be running from i-1 to 0
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                if(buy == 1)//suppose he has the liberty to buy, there are two choices, one is //he can buy or he can not buy
                {
                    int pick = -prices[ind] + prev[0];//if it is picked, then we move to the next index, where we cannnot buy, so buy = 0
                    int nonpick = 0 + prev[1];//we dont pick, so we move to the next index and we can still buy so buy = 1

                    profit = max(pick, nonpick);
                    cur[buy] = profit;
                }
                else
                {
                    int pick = prices[ind] + prev[1];//since we sell, amount on that added and then move to the next index, keeping buy=1, since we can buy anything as we have sold before

                    int nonpick = 0 + prev[0];// since we didnt sell, we add 0 and move to the next index, keeping buy=0, since we cannot buy anything

                    profit = max(pick, nonpick);
                    cur[buy] = profit;
                }
            }
            prev = cur;
        }
        
        return prev[1];//since tabulation is bottom up, we return the ans present at the top
    }
  
};




3.) Best Time to Buy and Sell Stock III


--> Find the maximum profit you can achieve. You may complete at most two transactions
--> same as the above problem, but except we introduce cap variable (no of transaction) and solve accordingly

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
  
  
Recursion solution: 


class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, int cap)
    {
        int profit = 0;
        if(ind == n)//if the index goes out of bound, then return 0
            return 0;
        
        if(cap == 0)
            return 0;
        
        if(buy == 1)//suppose he has the liberty to buy, there are two choices, one is he can buy or he can not buy
        {
            int pick = -prices[ind] + f(ind+1, 0, prices, n, cap);//if it is picked, then we move to the next index, where we cannnot buy, so buy = 0
            int nonpick = 0 + f(ind+1, 1, prices, n, cap);//we dont pick, so we move to the next index and we can still buy so buy = 1
            
            profit = max(pick, nonpick);
        }
        else
        {
            int pick = prices[ind] + f(ind+1, 1, prices, n, cap-1);//since we sell, amount on that added and then move to the next index, keeping buy=1, since we can buy anything as we have sold before
            
            int nonpick = 0 + f(ind+1, 0, prices, n, cap);// since we didnt sell, we add 0 and move to the next index, keeping buy=0, since we cannot buy anything
            
            profit = max(pick, nonpick);
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;//no of max transations is 2
        
        return f(0, 1, prices, n, cap);
        
    }
};



Memoization:



class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp, int cap)
    {
        int profit = 0;
        if(ind == n)//if the index goes out of bound, then return 0
            return 0;
        if(cap == 0)
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        if(buy == 1)//suppose he has the liberty to buy, there are two choices, one is he can buy or he can not buy
        {
            int pick = -prices[ind] + f(ind+1, 0, prices, n, dp, cap);//if it is picked, then we move to the next index, where we cannnot buy, so buy = 0
            int nonpick = 0 + f(ind+1, 1, prices, n, dp, cap);//we dont pick, so we move to the next index and we can still buy so buy = 1
            
            profit = max(pick, nonpick);
        }
        else
        {
            int pick = prices[ind] + f(ind+1, 1, prices, n, dp, cap-1);//since we sell, amount on that added and then move to the next index, keeping buy=1, since we can buy anything as we have sold before
            
            int nonpick = 0 + f(ind+1, 0, prices, n, dp, cap);// since we didnt sell, we add 0 and move to the next index, keeping buy=0, since we cannot buy anything
            
            profit = max(pick, nonpick);
        }
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<int>> dp(n, vector<int>(2, -1));//creating a n*2 dp table, 2 since buy can be either 0/1
        
        return f(0, 1, prices, n, dp, cap);
        
    }
};



Tabulation code:
