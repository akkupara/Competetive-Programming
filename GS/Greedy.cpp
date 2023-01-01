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
