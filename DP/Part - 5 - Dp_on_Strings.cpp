1.) Longest common Subsequence


--> A subsequence of a string is a new string generated from the original string with some characters 
(can be none) deleted without changing the relative order of the remaining characters.
  
--> For example, "ace" is a subsequence of "abcde".
  
--> A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
  
  
  
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
  
  

Recusive code:


class Solution {
public:
    int f(int ind1, int ind2, string s1, string s2)
    {
        if(ind1 < 0 || ind2 < 0)
            return 0;//base case
        
        if(s1[ind1] == s2[ind2])//match case
            return 1 + f(ind1-1, ind2-1, s1, s2);
        
        //non-match case
        return 0 + max(f(ind1-1, ind2, s1, s2), f(ind1, ind2-1, s1, s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        return f(n-1, m-1, text1, text2);
    }
};




Memoized code:


class Solution {
public:
    int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
    {
        if(ind1 == 0 || ind2 == 0)//actual base case represent negative indexes, but to make it easy we have shifted the indexes by 1
            return 0;//base case
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        
        if(s1[ind1-1] == s2[ind2-1])//match case and indexes shifted by 1 to fit in the base case when indexes are becoming negative
            return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s1, s2, dp);
        
        //non-match case
        return dp[ind1][ind2] = 0 + max(f(ind1-1, ind2, s1, s2, dp), f(ind1, ind2-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(n, m, text1, text2, dp);
    }
};



Tabulated code:

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int j=0; j <= m; j++)//base case
            dp[0][j] = 0;
        
        for(int i=0; i <= n; i++)//base case
            dp[i][0] = 0;
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])//match case I-1 & J-1 CUZ WE HAVE SHIFTED THE INDEX BY 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else//non match case
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};





2.) Longest common substring


--> In the previous qs, we found out the max len of lcs, here we have to print it
--> also we make the non-match condition as 0
--> from tabulation of the previous qs, we can find the max value in the dp table and return it to be the final answer



class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;//base case refer to previous qs
        }
        
        for(int i=0; i <= n; i++)
        {
            dp[i][0] = 0;//base case refer to previous qs
        }
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                //i-1 and j-1 cuz we shifted the indexes by 1
                if(S1[i-1] == S2[j-1])//each time when this condition holds, we updata and check maxi value
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi, dp[i][j]);
                }
                else
                    dp[i][j] = 0;//in this place the change is done
                    //in order to avoid discontinuity in the string, we equate it to 0
            }
        }
        return maxi;
    }
};







3.) Longest palindromic subsequence(LPS)
  
 
--> use the LCS code where we pass the string, reverse(string) as parameters to the LCS function


Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
  
  
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
  
  
  
class Solution {
public:
    int LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int j=0; j <= m; j++)//base case
            dp[0][j] = 0;
        
        for(int i=0; i <= n; i++)//base case
            dp[i][0] = 0;
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])//match case I-1 & J-1 CUZ WE HAVE SHIFTED THE INDEX BY 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else//non match case
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return LCS(s, t);
        
    }
};



4.) Minimum insertions to make a string palindrome


--> same as the LCS+LPS, where we keep the longest palindromic portion intact and keep a count of it
--> to find the longest palindromic part pass the string as parameter and find string.size() - LPS_size() which is the final ans


class Solution {
public:
    int LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int j=0; j <= m; j++)//base case
            dp[0][j] = 0;
        
        for(int i=0; i <= n; i++)//base case
            dp[i][0] = 0;
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])//match case I-1 & J-1 CUZ WE HAVE SHIFTED THE INDEX BY 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else//non match case
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int LPS(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return LCS(s, t);
        
    }
    int minInsertions(string s) {
        int n = s.size();
        int lps_size = LPS(s);
        
        int min_ins = n - lps_size;
        
        return min_ins;
        
    }
};



5.) Minimum operations to convert str1 to str2

--> Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

  
  Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
  
  
Input: word1 = "leetcode", word2 = "etco"
Output: 4
  
  
  

suppose two strings are there s, t 
int n = s.size()
int m = t.size()
  
no of deletions = n - len(LCS)
no of insertions = m - len(LCS)
  
ans = deletions + insertions



class Solution {
public:
    int LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int j=0; j <= m; j++)//base case
            dp[0][j] = 0;
        
        for(int i=0; i <= n; i++)//base case
            dp[i][0] = 0;
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])//match case I-1 & J-1 CUZ WE HAVE SHIFTED THE INDEX BY 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else//non match case
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        int deletion = n - LCS(word1, word2);
        int insertion = m - LCS(word1, word2);
        
        return deletion + insertion;
        
    }
};




6.) Shortest common supersequence

--> for finding the length of SCS, juz use the code of LCS
--> len(SCS) = n + m - len(LCS)
  
  Input: str1 = "brute", str2 = "groot"
Output: "bgruoote"
  
  
for len(SCS):


class Solution
{
    public:
    int LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int j=0; j <= m; j++)//base case
            dp[0][j] = 0;
        
        for(int i=0; i <= n; i++)//base case
            dp[i][0] = 0;
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])//match case I-1 & J-1 CUZ WE HAVE SHIFTED THE INDEX BY 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else//non match case
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return n + m - LCS(X, Y);
    }
};



for printing the SCS


class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int j=0; j <= m; j++)//base case
            dp[0][j] = 0;
        
        for(int i=0; i <= n; i++)//base case
            dp[i][0] = 0;
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])//match case I-1 & J-1 CUZ WE HAVE SHIFTED THE INDEX BY 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else//non match case
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int i=n, j=m;
        string ans = "";
        while(i > 0 && j > 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                ans = ans + s1[i-1];//add any one of the guys
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                ans = ans + s1[i-1];
                i--;
            }
            else if(dp[i][j-1] >= dp[i-1][j])
            {
                ans = ans + s2[j-1];
                j--;
            }
        }
        
        while(i > 0)
        {
            ans = ans + s1[i-1];
            i--;
        }
        
        while(j > 0)
        {
            ans = ans + s2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};


7.) Distinct Subsequences:


Input: s = "babgbag", t = "bag"

  
  
Memoized code:


class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if(j < 0)//if smaller string is exhausted, then match is found then return 1
            return 1;
        if(i < 0)//if bigger string itself is exhausted, then match is.not found, then return 0
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        if(s[i] == t[j])//match is found
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
        else//if match is not found
            return dp[i][j] = f(i-1, j, s, t, dp);//move i backwards and check if t is present in s
    }
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return f(n-1, m-1, s, t, dp);
        
    }
};




Tabulation code:


class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
        
        //base cases
        for(int i=0; i <= n; i++)//if smaller string is exhausted, then j becomes 0
            dp[i][0] = 1;//match is found
        
        for(int j=1; j <= m; j++)//if bigger string is exhausted and 1 based indexing and j=1 cuz we have put for j=0 in previous base case
            dp[0][j] = 0;//if match is not found
        
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])//match is found and change to 1-based indexing
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                
                else//if match is not found
                    dp[i][j] = dp[i-1][j];//move i backwards and check if t is present in s
            }
            
        }
        return int(dp[n][m]);//type cast into int from double
        
    }
};




Space optimisation code:


class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0), cur(m+1, 0);
        
        //base cases
//         for(int i=0; i <= n; i++)//if smaller string is exhausted, then j becomes 0
//             [0] = 1;//match is found
        
//         for(int j=1; j <= m; j++)//if bigger string is exhausted and 1 based indexing and j=1 cuz we have put for j=0 in previous base case
//             dp[0][j] = 0;//if match is not found
        
        prev[0] = cur[0] = 1;//change the format of the base case
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])//match is found and change to 1-based indexing
                    cur[j] = prev[j-1] + prev[j];
                
                else//if match is not found
                    cur[j] = prev[j];//move i backwards and check if t is present in s
            }
            prev = cur;
            
        }
        return int(prev[m]);//type cast into int from double
        
    }
};




8.) Edit Distance


--> same as minimum no of operations to convert on string to another(delete and insert only possible in that qs)
--> in this qs delete, insert and REPLACE is also possible which makes it little different


Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character




Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

  
  
Recursive code:
  
 class Solution {
public:
    int f(int i, int j, string s1, string s2)
    {
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        if(s1[i] == s2[j])
            return 0 + f(i-1, j-1, s1, s2);
        
        else
        {
            int ins = 1 + f(i, j-1, s1, s2);
            int del = 1 + f(i-1, j, s1, s2);
            int repl = 1 + f(i-1, j-1, s1, s2);

            return min(ins, min(del, repl));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        return f(n-1, m-1, word1, word2);
        
    }
};



tabulated code:


class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);
    
        else
        {
            int ins = 1 + f(i, j-1, s1, s2, dp);
            int del = 1 + f(i-1, j, s1, s2, dp);
            int repl = 1 + f(i-1, j-1, s1, s2, dp);

            return dp[i][j] = min(ins, min(del, repl));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i <= n; i++)
            dp[i][0] = i;
        
        for(int j=1; j <= m; j++)
            dp[0][j] = j;
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 0 + dp[i-1][j-1];

                else
                {
                    int ins = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int repl = 1 + dp[i-1][j-1];

                    dp[i][j] = min(ins, min(del, repl));
                }
                    
           }
        }
    
        return dp[n][m];
        
    }
};

