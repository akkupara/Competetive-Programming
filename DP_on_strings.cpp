1.) Longest common subsequence

--> Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

  Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
  
  
 Recursive solution: TC = O(2^m * 2^n) -- exponential (gives TLE)
   
 
   class Solution {
public:
    int f(int i, int j, string &text1, string &text2)
    {
        if(i < 0 || j < 0)//base case
            return 0;
        
        if(text1[i] == text2[j])
            return 1 + f(i-1, j-1, text1, text2);// we are adding one cuz we found one common subsequence, and then moving both the indexes backwards
        
        else
            return 0 + max(f(i-1, j, text1, text2), f(i, j-1, text1, text2));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        return f(n-1, m-1, text1, text2);
        
    }
};



USing memoization: TC = O(N * M) and SC = O(N * M)state storage in DP + O(N + M)for auxialiary stack space 

class Solution {
public:
    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0)//base case
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);// we are adding one cuz we found one common subsequence, and then moving both the indexes backwards
        
        else
            return dp[i][j] = 0 + max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n-1, m-1, text1, text2, dp);
        
    }
};




Tabulation(bottom-up approach)

 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));//n+1 and m+1 because, we are moving indexes by 1 towards right
        
        for(int j=0; j <= m; j++)
            dp[0][j] = 0;//base case, if it goes out of index
        for(int i=0; i <= n; i++)
            dp[i][0] = 0;// base case, if it goes out of index
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];// we are adding one cuz we found one common subsequence, and then moving both the indexes backwards
        
            else
                dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[n][m];
        
    }
};






Tabualtion with space optimisation:


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        
        for(int j=0; j <= m; j++)
            prev[j] = 0;//base case, if it goes out of index
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    cur[j] = 1 + prev[j-1];// we are adding one cuz we found one common subsequence, and then moving both the indexes backwards
        
            else
                cur[j] = 0 + max(prev[j] , cur[j-1]);
            }
            prev = cur;
        }
        
        return prev[m];
        
    }
};





2.) Print Longest common subsequence:(need to solve) feeling it tough right now

--> same as the above qs but we having print the LCS

You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.

Example 1:

Input: s = abaaa, t = baabaca
Output: aaaa abaa baaa
Example 2:

Input: s = aaa, t = a
Output: a




3.) Longest Common substring



Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.
  
  
 
-->Same as the tabulation with some changes and we return the max value in the dp table, which is the answer




Tabulation code:

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));//n+1 and m+1 because, we are moving indexes by 1 towards right
         for(int j=0; j <= m; j++)
            dp[0][j] = 0;//base case, if it goes out of index
        for(int i=0; i <= n; i++)
            dp[i][0] = 0;// base case, if it goes out of index
        
        int ans = 0;
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(S1[i-1] == S2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];// we are adding one cuz we found one common subsequence, and then moving both the indexes backwards
                    ans = max(ans, dp[i][j]);
                }
            else
                dp[i][j] = 0;//because its a substring and not a subsequence
            }
        }
        return ans;
    }
};




Tabulation code with space optimisation:



class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<int> prev(m+1, 0), cur(m+1, 0);//n+1 and m+1 because, we are moving indexes by 1 towards right
         for(int j=0; j <= m; j++)
            prev[j] = 0;//base case, if it goes out of index
        for(int i=0; i <= n; i++)
            cur[0] = 0;// base case, if it goes out of index
        
        int ans = 0;
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(S1[i-1] == S2[j-1])
                {
                    cur[j] = 1 + prev[j-1];// we are adding one cuz we found one common subsequence, and then moving both the indexes backwards
                    ans = max(ans, cur[j]);
                }
            else
                cur[j] = 0;//because its a substring and not a subsequence
            }
            prev = cur;
        }
        return ans;
    }
};



