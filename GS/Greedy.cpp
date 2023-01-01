1.) Container with most water


--> You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

--> Return the maximum amount of water a container can store.
  
--> if start bar is smaller than end bar, increment start bar, and if start bar is greater than end bar, then decrement end bar



class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j = n-1;
        int area = 0;
        
        int ans = 0;
        
        while(i < j)
        {
            if(height[i] <= height[j])
            {
                area = (j-i)*height[i];
                i++;
            }
            else
            {
                area = (j-i)*height[j];
                j--;
            }
            ans = max(ans, area);
        }
        return ans;
    }
};




2.) Minimise the difference between maximum height - I

--> need to revise it again
--> Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once.
  
--> Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

  
  
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
  
  
  
  
  
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int currmin = arr[0];
        int currmax = arr[n-1];
        int ans = currmax - currmin;
        
        for(int i=1; i < n; i++)
        {
            currmin = min(arr[0]+k, arr[i]-k);
            currmax = max(arr[i-1]+k, arr[n-1]-k);
            ans = min(ans, currmax-currmin);
        }
        return ans;
    }
};




3.) Minimise the difference between maximum height - II

--> need to revise it again
--> Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once.
  
--> Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower. 

--> Same as the previous qs difference should not be negative, for that we just add one extra if condition.
 
  
  
  
  class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int currmin = arr[0];
        int currmax = arr[n-1];
        int ans = currmax - currmin;
        
        for(int i=1; i < n; i++)
        {
            if(arr[i] >= k)
            {
                currmin = min(arr[0]+k, arr[i]-k);
                currmax = max(arr[i-1]+k, arr[n-1]-k);
                ans = min(ans, currmax-currmin);
            }
            
        }
        return ans;
    }
};






-
