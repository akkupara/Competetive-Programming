1.) Move Zeros

--> Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
--> Note that you must do this in-place without making a copy of the array.
  
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) 
            {
                nums[j] = nums[i];//move all elements to the left side fully 
                j++;
            }
            else
                continue;
        }
        
        for(;j < nums.size(); j++)//start from where j stoped in the previous iteration
            nums[j] = 0;
        
    }
};



2.) Rotate array

--> Given an array, rotate the array to the right by k steps, where k is non-negative.
--> Expected to do it in-place


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]


BUT USES EXTRA SPACE: TC = O(N)+ O(N) and SC = O(N)
  
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0; i < n; i++)
        {
            temp[(i+k)%n] = nums[i];
        }
        
        nums = temp;//copy whatever is there in temp
    }
};


NICE APPROACH: TC = O(N) and SC = O(1)

  
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        
        reverse(nums.begin(), nums.begin()+n-k);//reverse first n-k numbers
        reverse(nums.begin()+n-k, nums.end());//reverse the last k numbers
        
        reverse(nums.begin(), nums.end());//reverse the whole array
    }
};
