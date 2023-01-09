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
