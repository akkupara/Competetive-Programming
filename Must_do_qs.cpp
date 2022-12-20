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
