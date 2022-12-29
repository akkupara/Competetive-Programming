1.) 3 sum

Given an integer array nums, 
return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
  
  
  
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]






class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i < n-2; i++)
        {
            if(i == 0 ||(i > 0 && nums[i-1] != nums[i]))
            {
                int low = i+1, high = n-1;
                int sum = 0 - nums[i];
                while(low < high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        
                        while(low < high && nums[low] == nums[low+1])
                            low++;
                        while(low < high && nums[high] == nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum)
                        low++;
                    else
                        high--;
                    
                }
            }
        }
        return ans;
        
    }
};




2.) Remove Duplicates from sorted Array

--> Return the no of unique elements presents in the array

Input: nums = [1,1,2]
Output: 2,

the unique elements present are 1 and 2.
  
  
Brute approach:

--> put the elements into a hashset and return the size of the hashset which stores only the unique elements.
--> TC = O(N log N) + O(N) for putting the elements into the hashset  + for again placing it back into the array
--> SC = O(N)
  
  
 
Optimal approach: Using Two pointer ---------------revise the approach once again


--> TC = O(N) and SC = O(N) because we are modifying the array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int i=0;
        for(int j=1; j < n; j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};




3.) Set Matrix to zero

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1]
                 [1,0,1]
                 [1,1,1]]
Output: [[1,0,1]
         [0,0,0]
         [1,0,1]]
         


Example 2:


Input: matrix = [[0,1,2,0]
                 [3,4,5,2]
                 [1,3,1,5]]
Output: [[0,0,0,0]
         [0,4,5,0]
         [0,3,1,0]]
 


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //we use the dummy arrays as the 0th row and col of the matrix
        // arr[0][0] is common to both row 0 and column 0
        //so while encountering 0, we update col0 and not arr[0][0] for columsn
        //for row updation we use arr[0][0]
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        
        for(int i=0; i < rows; i++)
        {
            //we check the value of the 0th column and ith row, if zero, we make col0 = 0
            if(matrix[i][0] == 0)
                col0 = 0;
            
            for(int j=1; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;//if any element is 0, we make 0th row and column 0
            }
            
        }
        
        
        
        for(int i=rows-1; i >= 0; i--)
        {
            for(int j=cols-1; j >= 1; j--)//till index 1, since for 0th column, we maintain col0 variable
            {
                if(matrix[i][0] == 0|| matrix[0][j] == 0)//if any those dummy arrays are marked as 0, make that indexes i, j as 0
                    matrix[i][j] = 0;
            }
            if(col0 == 0)
                matrix[i][0] = 0;//col0 = 0 means oth col is set to zero
            
        }
        
        
    }
};
