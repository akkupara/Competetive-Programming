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


3.) SUBARRAY WITH GIVEN SUM

--> Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

--> A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
  
  
BRUTE FORCE APPROACH: TC = O(N*N) and SC = O(1)
  
  
  
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        for(int i=0; i < n; i++)
        {
            int sum = nums[i];
            
            if(sum == k)
                count++;
            
            for(int j=i+1; j < n; j++)
            {
                sum = sum + nums[j];
                if(sum == k)
                    count++;
            }
        }
        return count;
    }
};



MOst Optimal solution


class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // take the size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum
        
        prefix[0] = arr[0]; // for element at index at zero, it is same
        
        // making our prefix array
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // declare an unordered map
        
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }
            
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};




4.) 
  
--> algorithm that searches for a value target in an m x n integer matrix matrix
--> Integers in each row are sorted from left to right.
--> The first integer of each row is greater than the last integer of the previous row.
  Input: matrix = 
    [1 , 3, 5, 7]
    [10,11,16,20]
    [23,30,34,60], target = 3
Output: true
  
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int index = 0;

        int i=0, j = n-1;
        while(i < m && j > -1)
        {
            if(matrix[i][j] == target)
                return true;
            
            
            if(matrix[i][j] > target)//move left
                j--;
            else if(matrix[i][j] < target)//move down
                i++;
        }
        
        return false;
        
        
    }
};



5.) Row with maximum 1
  
  
--> We have to return the row number in which maximum no of 1's are present
--> Can be solved by three approaches

--> Using ladder approach is more suitable and efficient



class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row = 0, col = m-1;
	    
	    int ans = -1;
	    
	    while(row < n && col >= 0)
	    {
	        if(arr[row][col] == 1)
	        {
	            col--;
	            ans = row;
	        }
	        else
	            row++;
	    }
	    return ans;
	}

};




6.) Leaders in an array

--> An element of array is leader if it is greater than or equal to all the elements to its right side. 
--> The rightmost element is always a leader

nput:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
  
  
Brute force approach: TC = O(N*N) and SC = O(N) and gives TLE

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int nums[], int n){
        
        vector<int> ans;
        
        for(int i=0; i < n; i++)
        {
            int j;
            for(j=i+1; j < n; j++)
            {
                if(nums[j] > nums[i])
                    break;
            }
            if(j==n)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};


Optimal solution: TC = O(N) and SC = O(N)
  

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int nums[], int n){
        
        vector<int> ans;
        
        int max_ele = nums[n-1];
        
        ans.push_back(nums[n-1]);
        
        for(int i=n-2; i >=0; i--)
        {
            
            if(nums[i] >= max_ele)
                ans.push_back(nums[i]);
                max_ele = max(max_ele, nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


11.) Longest consecutive sequeunce

--> Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
--> Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
  
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hashSet;///creating a set
        for(int num: nums)
            hashSet.insert(num);//inserting all the elements of vector into the set
        
        int longestStreak = 0;//ans which is going to be returned
        int cur_streak, cur_num;
        
        
        for(int num: nums)
        {
            if(hashSet.count(num-1) == 0)//if it is not there in the hashset
            {
                cur_num = num;//used to find the minimum among the longest consecutive
                cur_streak = 1;
            
                while(hashSet.count(cur_num+1) == 1)
                {
                    cur_num += 1;
                    cur_streak += 1;
                } 

                longestStreak = max(longestStreak, cur_streak);
        }
    }
        
        return longestStreak;
    }
};




13.) Spiral matrix traversal

--> Given an m x n matrix, return all elements of the matrix in spiral order.
--> Input: matrix = [1,2,3]
                    [4,5,6]
                    [7,8,9]
                    
Output: [1,2,3,6,9,8,7,4,5]



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0;//initially dir is 0
        
        vector<int> ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top = 0;
        int down = n-1;
        
        int left = 0;
        int right = m-1;
        
        while(top <= down && left <= right)
        {
            if(dir == 0)
            {
                for(int i=left; i <= right; i++)
                    ans.push_back(matrix[top][i]);
                top++;
            }
            
            else if(dir == 1)
            {
                for(int i=top; i <= down; i++)
                    ans.push_back(matrix[i][right]);
                right--;
            }
            
            else if(dir == 2)
            {
                for(int i=right; i >= left; i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            
            else if(dir == 3)
            {
                for(int i=down; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};


6.) 3 Sum

--> Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
  
--> Notice that the solution set must not contain duplicate triplets.
--> Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;//to store the triplets which is the ans
        
        int low;
        int high;
        int sum;
        
        for(int i=0; i < nums.size()-2; i++)//till nums.size()-2 because we have to find two more elements
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))//if i is 0 or when i is greater than 0, then we should consider the element already taken
            low = i+1;
            high = nums.size()-1;
            sum = 0-nums[i];
            
            while(low < high)
            {
                if(nums[low] + nums[high] == sum)
                {
                    vector<int> temp;//to temporarily make the triplet
                    
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    
                    ans.push_back(temp);
                    
                    while(low < high && nums[low] == nums[low+1])//remove all the duplicates
                        low++;
                    
                    while(low < high && nums[high] == nums[high-1])//remove all the duplicates
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
        return ans;
    }
};



8.) maximum subarray with sum 0
  
  
--> task is to compute the lenght of the largest subarray with sum 0
--> A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
  
  
 class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> mpp;
        int maxi = 0; //return the maximum length
        int sum = 0; //stores the summation of array elements
        
        for(int i=0; i < n; i++)
        {
            sum = sum + A[i];//first add the elements and check for two possibilities
            if(sum == 0)
                maxi = i+1;//{if the subarray is in starting}
            else
            {
                if(mpp.find(sum) != mpp.end())//if the subarray is not in the starting
                    maxi = max(maxi, i-mpp[sum]);//check if it is already present in the hashmap
                    //and if the same sum is encountered again find that index and return i-that index
                else
                    mpp[sum] = i;//if not present, add it to the hash-map add (sum, index)
            
            }
        }
        return maxi;
    }
};




9.) Find the missing and repeating number

using mathematics

class Solution{
public:
    int *findTwoElement(int *nums, int n) {
        // code here
        long long int s = (n*(n+1))/2;
        long long int p = (n*(n+1)*(2*n+1))/6;
        
        int missing = 0, repeat = 0;
        
        for(int i=0; i < n; i++)
        {
            s = s - (long long int) nums[i];
            p = p - (long long int) nums[i]*long long int nums[i]);
            
        }
        
        missing = (s + (p/s))/2;
        repeating = missing - s;
        
        vector<int> ans;
        ans.push_back(repeating);
        ans.push_back(missing);
        
        return ans;
    }
};
