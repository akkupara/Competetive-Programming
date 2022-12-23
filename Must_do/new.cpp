optimal solution:


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


-->  An element of array is leader if it is greater than or equal to all the elements to its right side. 
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
-->  Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other
--> At any given instance of time, same platform can not be used for both departure of a train and arrival of another train.


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




