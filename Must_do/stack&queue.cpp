1.) Valid Parantheses


--> Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Input: s = "()"
Output: true
    
    
Input: s = "(]"
Output: false
    
    
    
--> the approach is he idea is to put all the opening brackets in the stack. 
--> Whenever you hit a closing bracket, search if the top of the stack is the opening bracket of the same nature. 
--> If this holds then pop the stack and continue the iteration, in the end if the stack is empty, it means all brackets are well-formed . 
--> Otherwise, they are not balanced.
    
    
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        
        for(int i=0; i < n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if((st.top() == '(' && s[i] == ')')
                   || (st.top() == '{' && s[i] == '}')
                   ||(st.top() == '[' && s[i] == ']'))
                st.pop();
            else
                st.push(s[i]);
        }
        
        if(st.empty())
            return true;
        return false;
    }
};





2.) Next greater element


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
