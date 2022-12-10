1.) Longest Substring Without Repeating Characters


Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
  
  
 Naive Approach:
  
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size()==0)
          return 0;
          int maxans = 0;
          for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
          {
            unordered_set < int > set;
            for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
            {
              if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
              {
                maxans = max(maxans, j - i);
                break;
              }
              set.insert(str[j]);
            }
          }
          return maxans;
            }
};



Optimised approach:


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





2.) Maximum consecutive ones III


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int right=0;//moves ahead
        int left = 0;//moves at back of j
        
        while(right < n)
        {
            if(nums[right] == 0)
                k--;
            
            if(k < 0)
            {
                if(nums[left] == 0)
                {
                    k++;
                }
                left++;
            }
            
            right++;
        }
        return right-left;
    }
};



Good code:


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0, left = 0;
        int maxLen = 0;
        for( int right = 0; right < nums.size() ; right++ ) {
            if( nums[right] == 0 ) 
                zero++;
            
            while(k < zero) 
            {
                if( nums[left] == 0 ) 
                    zero--;
                
                left++;
            }
            
            maxLen = max( maxLen, right - left + 1 );
        }
        return maxLen;
    }
};

