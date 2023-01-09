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



  
  
