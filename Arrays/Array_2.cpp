1.) Rotate matrix

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
  
--> first transpose it
--> then reverse it row wise


TC = O(N*N) + O(N*N). SC = O(1)
  
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i < n; i++)
            for(int j=0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);//first transpose the matrix
        
        for(int i=0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());//then reverse it row wise

        
        
    }
};




2.) Merged Intervals

--> Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
  
--> Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

--> Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        
        for(int i=1; i < n; i++)
        {
            if(output.back()[1] >= intervals[i][0])
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            else
                output.push_back(intervals[i]);
        }
        return output;
    }
};




3.) Merge two sorted arrays

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
  
  
 TC = O(M+N) and SC = O(1)
  
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else if(nums1[i] <= nums2[j])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        
        while(i >= 0)
        {
            nums1[k] = nums1[i];
            i--;
            k--;
            
        }
        while(j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
            
        }
        
    }
};


4.) Duplicate number

--> intuition of the optimal approach:

The repeated number will always be at the junction between the straight path and the cycle because, the cycle exists only because two nodes reach to the same next as one value is repeated. We traverse the array and we go to the element at the index same as the current element value. Since there is a
repeated value, we would be going to a index twice, hence there will be cycle if there is a repeated value. This method is only applicable to questions in which all elements are between 0 and array.length - 1 . Two pointer in a cycle, starting at the same point and moving at different speeds will always 
collide at some point. At any point when the slow and fast pointers collide the fast pointer must have covered twice the distance of the slow pointer because its moving two steps in every iteration while slow pointer moves only one. And where would the fast point move that extra distance? It could only 
move that in the cycle because that is only how it could come back the same point in the cycle, as the slow and fast are colliding at a point in the cycle, hence the distance moved by the slow pointer would be multiple of the length of the cycle. At last we  would move both the slow and fast pointer by
one step until they meet again and that would be our duplicate number.
  
--> using two pointers


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];//moving by 1
            fast = nums[nums[fast]];//moving by 2
        }
        while(slow != fast);
            
        fast = nums[0];
        
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
