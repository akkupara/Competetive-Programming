1.) Subsets


--> Given an integer array nums of unique elements, return all possible subsets (the power set).

--> The solution set must not contain duplicate subsets. Return the solution in any order.
  
  
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
  
  
  
  
 powerset TC: O(2^N)
  
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size(); //if n = 3, subsets = 2^n
        for(int i=0; i < pow(2, n); i++)
        {
            vector<int> vec;
            for(int j=0; j < n; j++)
            {
                if((1 << j) & i)//checking if the bit is set or not
                    vec.push_back(nums[j]);
            }
            ans.push_back(vec);
        }
        return ans;
        
    }
};



2.) Kth Largest Element in an Array


--> Given an integer array nums and an integer k, return the kth largest element in the array.
--> You must solve it in O(n) time complexity.
  
  
  
Input: nums = [3,2,1,5,6,4] after sorting [1, 2, 3, 4, 5, 6], k = 2
Output: 5 ( 2nd largest element is 5)
  
  
  
--> Method 1 - using sorting and reversing: TC = O(N Log N)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        return nums[k-1];
        
    }
};




--> Method 2 - Using max heap: TC --> O(N + Klog N for heapifying)
  
  
  int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int> pq(nums.begin(),nums.end());
	for(int i=1;i<k;++i) pq.pop();
	return pq.top();
}


--> Method 3 - using nth_element. TC = O(N)
  
  
  int findKthLargest(vector<int>& nums, int k) {
	nth_element(nums.begin(),
              nums.begin()+nums.size()-k,nums.end());
	return nums[nums.size()-k];
}


--> need to learn quick select which is the most optimal method


3.) Palindromic substring - need to revise it again


--> Given a string s, return the number of palindromic substrings in it.
  
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
  
  
  
  
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool> (n, false));//intitally fill it with false values
        
        int count = 0;
        
        for(int diff=0; diff < n; diff++)
        {
            for(int i=0, j=diff; j < n; i++, j++)
            {
                if(diff == 0)//fill all the first diagonal with zeros
                    dp[i][j] = true;
                else if(diff == 1)//seocnd diagonal
                {
                    if(s[i] == s[j])
                        dp[i][j] = true; 
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = dp[i+1][j-1];
                        
                    }
                    else
                        dp[i][j] = false;
                }
                if(dp[i][j])
                count++;
            }
            
        }
        
        return count;
        
    }
};
  
  
