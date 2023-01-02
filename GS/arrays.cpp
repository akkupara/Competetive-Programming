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




3.) Next greater element


--> arr[] = [1 3 2 4]
Output:
3 4 4 -1
    
--> Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
    
--> If there does not exist next greater of current element, then next greater element for current element is -1. 


Brute solution:


class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        vector<long long> ans;
        int next;
        for(int i=0; i < n; i++)
        {
            next = -1;
            for(int j=i+1; j < n; j++)
            {
                if(nums[i] < nums[j])
                {
                    next = nums[j];
                    break;
                }
            }
            ans.push_back(next);
        }
        return ans;
    }
};




Optimised Solution:


lass Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n);
        stack<long long> st;
        st.push(-1);
        for(int i = n-1 ; i >= 0 ;i--) {
            while(st.top() != -1 && arr[i] >= st.top()) 
                st.pop();
            
            ans[i] = st.top();
            st.push(arr[i]);
       
        }
        return ans;
    }
};




4.) Diagonal Traverse

--> Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
  
  
Important resource:  https://www.youtube.com/watch?v=NTF7sDU0IWA

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        
        
        if(matrix.size() == 0 || matrix[0].size() == 0)//if the size of the matrix is zero then return empty matrix
            return ans;
    
        int i = 0;//index
        
        int row = 0, col = 0;//starting point where the traversal starts
        
        //we can either traverse in up or down direction
        bool up = true;
        
        while(row < m && col < n)
        {
            //case I when diagonal is going up
            if(up)
            {
                while(row > 0 && col < n-1)
                {
                    ans.push_back(matrix[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(matrix[row][col]);
                if(col == n-1)
                    row++;
                else
                    col++;
            }
            
            //case II when diagional is going down
            else
            {
                while(col > 0 && row < m-1)
                {
                    ans.push_back(matrix[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(matrix[row][col]);
                if(row == m-1)
                    col++;
                else
                    row++;
            }
            up = !up;
        }
        return ans;
    }
};



5.) Diagonal Traverse II


--> Same as the previous question but the way we traverse is different
--> we traverse using two loops where we enter i+j, j, nums[i][j] into the 2D vector, in each diagonal taversal i+j 
turns out to be the same

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < (int)nums[i].size(); j++)
            {
                ans.push_back({i+j, j, nums[i][j]});//
            }
        }
        sort(ans.begin(), ans.end());
        
        vector<int> res;
        for(int i=0; i < (int)ans.size(); i++)
            res.push_back(ans[i][2]);
        
        return res;
    }
};



Q) CHECK IF TWO STRINGS ARE SIMILAR

--> Two strings word1 and word2 are considered almost equivalent if the differences between the 
frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.
  
  
--> here we maintain two frequency array where we take the difference of the frequency and return the answer accordingly


class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        
        
        
        int count1[26] = {0};
        int count2[26] = {0};
        
        for(char c: word1)
        {
            count1[c - 'a']++;
        }
        
        for(char c: word2)
        {
            count2[c - 'a']++;
        }
        
        for(int i=0; i < 26; i++)
        {
            if(abs(count1[i]- count2[i]) > 3)
                return false;
        }
        
        
        return true;
    }
};




Q) Group Anagrams


--> Given an array of strings strs, group the anagrams together. You can return the answer in any order.

  
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]



--> The idea is to maintain a map where we sort the input string index wise and keep it as key, if that key matches and add that element to that bucket


TC = O(N * K log K), where K is the size of the individual string


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        unordered_map<string, vector<string> > mpp;
        int n = str.size();
        string temp;//to store the original string, cuz after sorting the order changes, so we keep a copy of the original string
        
        for(int i=0; i < n; i++)
        {
            temp = str[i];
            sort(str[i].begin(), str[i].end());//sorted string
            mpp[str[i]].push_back(temp);//sorted string is the key
        }
        
        vector<vector<string>> ans;
        
        for(auto it=mpp.begin(); it != mpp.end(); it++)
            ans.push_back(it->second);
        
        return ans;
    }
};




------------Need to optimise it




