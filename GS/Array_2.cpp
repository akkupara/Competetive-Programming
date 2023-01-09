1.) Majority element

--> Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
  
  
  Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

  
  
Naive approach:

pick one element and check its no of occurrence in the array which will take TC = O(N*N)
    
    
Optimal approach: Use hashmap

(element, count) - O(N)
  
  and then check which count is greater than n/2
  
 
 Most optimal apprioach: Moores voting algortihm
 
 
 pseudo-code of algorithm
 
 if(cnt == 0)
    ele = arr[i]
    
 if(ele == arr[i])
   cnt++;
 else
   cnt--;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele = 0;
        
        for(int i=0; i < n; i++)
        {
            if(cnt == 0)
                ele = nums[i];
            
            if(ele == nums[i])
                cnt++;
            else
                cnt--;
        }
        return ele;
    }
};



QS) Majority element II

Find the majority element that appears more than n/3 times (there can be more than two majority elements)
  
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]

Example 2:

Input: nums = [1]
Output: [1]

Example 3:

Input: nums = [1,2]
Output: [1,2]




class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1;
        int c1 = 0, c2 = 0;
        for(int i=0; i < n; i++)
        {
            if(nums[i] == num1)
                c1++;
            else if(nums[i] == num2)
                c2++;
            else if(c1 == 0)
            {
                num1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0)
            {
                num2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        c1 = c2 = 0;
        
        for(int i=0; i < n; i++)
        {
            if(nums[i] == num1)
                c1++;
            else if(nums[i] == num2)
                c2++;
        }
        if(c1 > n/3)
            ans.push_back(num1);
        if(c2 > n/3)
            ans.push_back(num2);
        
        return ans;
    }
};




2.) Largest consecutive subsequence

brute: first sort and check the largest consecutive subsequence TC = O(n log n) + O(N) and SC = O(1)
  
  int longestConsecutive(vector<int> nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
  
Optimal approah: using hashmap(set in c++) TC = O(N) and Sc = O(N)
  

  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;//create a hashmap 
        for(int num: nums)
            hashset.insert(num);//insert all the elements into the hashset
        
        int largestStreak = 0;
        
        for(int num: nums)
        {
            //check if nums[i]-1 exists in the hashmap
            if(!hashset.count(num-1))//if it does not exist then check if nums[i]+1 exists or not
            {
                int currnum = num;
                int currentStreak = 1;
                
                while(hashset.count(currnum+1))//if curnum+1 existes in the hashmap, then proceed
                {
                    currnum += 1; //increment it by 1 sicne all of them are in ascending order
                    currentStreak += 1;
                }
                largestStreak = max(largestStreak, currentStreak);
            }
        }
        return largestStreak;
    }
};



4.) Largest Subarray with 0 sum

--> Naive solution: check all subarrays which has zero sum and has the greatest length
TC = O(N*N)
  
  
class Solution{
       int maxi = 0;
      public:
    int maxLen(vector<int>&nums, int n)
    {   
       for(int i=0; i < n; i++)
        {
            int sum = 0;
            for(int j=i; j < n; j++)
            {
                sum = sum + nums[j];
                
                if(sum == 0)
                    maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    }
};


  
--> Optimal solution:

--------- we are going to maintain a hashmap of (prefix-sum, index) and check if that prefix-sum occurs again in the hashmap and 
  then subtract the indexes to update the maximum length subarray
  
--> tc = 0(n) AND SC = O(N) for the hashmap


class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        unordered_map<int, int> mpp;
        int maxi = 0;
        int sum = 0;
        
        for(int i=0; i < n; i++)
        {
            sum = sum + nums[i];
            if(sum == 0)
                maxi = i + 1;//from the first index till the current index the subarray adds to 0
            else
            {
                if(mpp.find(sum) != mpp.end())//if we encounter that sum again
                {
                    maxi = max(maxi, i-mpp[sum]);
                }
                else
                    mpp[sum] = i;//if the prefuix sum doesnt appear, then just insert it into the hashmap
            }
        }
        return maxi;
    }
};




5.) Longest Substring Without Repeating Characters


Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
  


  
--> Naive approach: TC = O(N*N) and SC = O(N) which is used to check the repeating characters

Using kadane algorithm generate all the substrings and check the one which has the longest substring

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);//all initialised to 0 and it can have max of 256 characters
        
        int n = s.size();
        int left = 0, right = 0;//left and the right pointers
        
        int len = 0;//returned to be the answer
        
        while(right < n)//iterate till the last index
        {
            if(mpp[s[right]] != -1)//checking if it exists
                left = max(mpp[s[right]] + 1, left);
            // if it exist then move left to the ind+1
            //if it does not exist, left stays there 
            
            mpp[s[right]] = right;//insert the element with new index
            
            len = max(len, right-left+1);//calculate max_len each iteration
            right++;//move right to the next index
        }
        return len;
    }
};

