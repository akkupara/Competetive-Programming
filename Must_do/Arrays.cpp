1.) Subarray with given sum

N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.




class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>nums, int n, long long s)
    {
        vector<int> ans;
        int start = 0, flag = 0, sum = 0;

        for(int i=0; i < n; i++)
        {
            sum = sum + nums[i];

            while(s < sum)
            {
                sum = sum - nums[start];
                start++;
            }

            if(sum == s)
            {
                ans.push_back(start+1);
                ans.push_back(i+1);
                flag = 1;
                break;
            }

        }
        if(flag == 0)
            ans.push_back(-1);
        return ans;
    }
};



2.) count Triplets


Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Example 1:

Input: 
N = 4 
arr[] = {1, 5, 3, 2}
Output: 2 
Explanation: There are 2 triplets:
 1 + 2 = 3 and 3 +2 = 5




class Solution{
public:	

	int countTriplet(int arr[], int n)
	{
	    int count = 0;
	    int index[100000] = {0};
	    for(int i=0; i < n; i++)
	        index[arr[i]] = 1;

	    for(int i=0; i < n-1; i++)
	    {
	        for(int j=i+1; j < n; j++)
	        {
	            if(index[arr[i]+arr[j]] == 1)
	                count++;
	        }

	    }
	    return count;
	}
};




Better solution


class Solution{
public:	

	int countTriplet(int arr[], int n)
	{
	    //int count = 0;
	    unordered_set<int> s;

        for(int i = 0 ; i < n ; i++){

            s.insert(arr[i]);

        }

        int count = 0;

        for(int i = 0 ; i < n-1 ; i++){

           for(int j = i+1 ; j < n ; j++){

               if(s.find(arr[i]+arr[j]) != s.end()) 
                    count++;

           }

        }

        return count;
	}
};




3.) Maximum subarray sum


--> Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.



long long maxSubarraySum(int arr[], int n){

        int sum = 0;
        int maxi = INT_MIN;
        // Your code here
        for(int i=0; i < n; i++)
        {
            sum = sum + arr[i];
            if(sum > maxi)
                maxi = max(maxi, sum);

            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }






4.) Merge two sorted arrays


--> there are various methods of solving this question,
--> gap method
--> used a map where the property of map is used to solve the qs
--> maps are always sorted in order
--> using sc = O(1) is the most optimal one-------need to look into it





5.) Rearrange array alternately
	
--> Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, 
second should be min value, third should be second max, fourth should be second min and so on.	
	
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.
	
	
There are two pointers min, max, where min points 0th index and max points to the last index
For even indexes

A[i] = A[i] + ((A[max] % N) * N)


For odd indexes

A[i] = A[i] + ((A[min] % N) * N)
	
	
	
void rearrange(long long *nums, int n) 
    { 
        int maxi = n-1;
        int mini = 0;
        
        int N = nums[n-1]+1;
        
        for(int i=0; i < n; i++)
        {
            if(i % 2 == 0)//for even indexes
            {
                nums[i] = nums[i] + ((nums[maxi] % N)* N);
                maxi--;
            }
            else
            {
                nums[i] = nums[i] + ((nums[mini] % N)* N);
                mini++;
            }
        }
        
        for(int i=0; i < n; i++)
        {
            nums[i] = nums[i] / N;
        }
    }
};





5.) count inversion


--> Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then 
the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
	
--> Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
	
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
	
	

	
6.) sort 0, 1, 2 -------> highly important


Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]


--> first sort using built in function - TC = O(N log N)
--> use counting sort - TC = O(N) + O(N)
	
--> this is not binary search (dutch national flag algorthim) -- TC = O(N) use three pointers low, mid, high

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0, mid = 0;
        int high = n-1;
        
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
                mid++;
            else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};



7.) Equilibrium Point

--> Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
	
A[] = {1,3,5,2,2} 
Output: 3 
Explanation:  
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2). 
	
	
	
brute method - o(N^2)
	

int n = nums.size();
        int i, j;
        
        int leftsum, rightsum;
        for(i=0; i < n; i++)
        {
            leftsum = 0;
            for(int j=0; j < i; j++)
                leftsum += nums[j];
            
            rightsum = 0;
            for(int j=i+1; j < n; j++)
                rightsum += nums[j];
            
            if(leftsum == rightsum)
                return i;
        }
        return -1;
}



Optimised soln:


