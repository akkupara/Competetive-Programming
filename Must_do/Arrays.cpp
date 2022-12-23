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


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        int leftsum = 0;
        
        for(int i=0; i < n; i++)
            totsum += nums[i];
        
        for(int i=0; i < n; i++)
        {
            totsum = totsum - nums[i];
            
            if(leftsum == totsum)
                return i;
            
            leftsum = leftsum + nums[i];
        }
        return -1;
    }
};



8.) Leaders in an array


-->  An element of array is leader if it is greater than or equal to all the elements to its right side. 
--> The rightmost element is always a leader. 


A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.


class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int nums[], int n){
        vector<int> ans;
        ans.push_back(nums[n-1]);
        int maxi = nums[n-1];
        
        for(int i=n-2; i >= 0; i--)
        {
            if(nums[i] >= maxi)
            {
                ans.push_back(nums[i]);
                maxi = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



9.) Minimum no of platforms

-->  Find the minimum number of platforms required for the railway station so that no train is kept waiting.
-->  Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other
--> At any given instance of time, same platform can not be used for both departure of a train and arrival of another train.


arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.


note: ask the interviewer if the time are sorted or not


approach: Gredy algorthim

1.) first, sort both the arrival and departure array in ascending order, yes the order of timimgs will be lost 
2.) then check how many platforms it takes to accomodate

TC = O(2N logN) + o(2N)// sorting two times and using two pointers to traverse the arrays
SC = O(1)



class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int platform_needed = 1;//assume 1 platform is needed defaultly
        int result = 1;//same goes with the result
        
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=1, j=0; //i is equal to 1, cuz we assume the first train has already arrived
    	
    	while(i < n && j < n)
    	{
    	    if(arr[i] <= dep[j])//means an extra platform is needed
    	    {
    	        platform_needed++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j])////that platform is reduced and for better understanding dryrun it
    	    {
    	        platform_needed--;
    	        j++;
    	    }
    	    
    	    if(platform_needed > result)
    	        result = platform_needed;
    	}
    	return result;
    }
};



10.) Reverse arrays in groups

--> Reverse every sub-array group of size K.
--> N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
	
	


class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& nums, int n, int k){
        
        
        for(int i=0; i < n; i+=k)
        {
            int left = i;
            int right = min(i+k-1, n-1);
            
            while(left < right)
            {
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
    }
};






11.) Kth smallest element


--> i solved using pririty queue
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(log(n))
	


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        for(int i=0; i < r-l+1; i++)
        {
            pq.push(arr[i]);
            
            if(pq.size() > k)
                pq.pop();
        }
            
        return pq.top();
    }
};




12.) Last Index of one


--> Given a string S consisting only '0's and '1's,  find the last index of the '1' present in it.
	
	
Input:
S = 00001
Output:
4
Explanation:
Last index of  1 in given string is 4.
	
	
	
class Solution{
    public:
    int lastIndex(string s) 
    {
        int n = s.size();
        int index = -1;
        int maxi = -1;
        
        for(int i=0; i < n; i++)
        {
            if(s[i] == '1')
            {
                index = i;
                maxi = max(maxi, index);
            }
            
        }
        return maxi;
    }

};



14.) Largest Number formed from an array


Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.
	
	
	
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool comparator(string s1, string s2)
	{
	    string first = s1 + s2;
	    string second = s2 + s1;
	    
	    for(int i=0; i < first.size(); i++)
	    {
	        if(first[i] > second[i])//no swapping will be done
	            return true;
	        else if(second[i] > first[i])//sqapping will be done
	            return false;
	    }
	    return false;
	}
	string printLargest(vector<string> &arr) {
	    // code here
	    int n = arr.size();
	    string res = "";
	    sort(arr.begin(), arr.end(), comparator);
	    for(int i=0; i < n; i++)
	    {
	        res.append(arr[i]);
	    }
	    return res;
	}
};




