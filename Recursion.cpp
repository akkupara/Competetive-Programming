1.) Pow(x, n)
  
--> The brute force approach is check the sign, and calculate the sum using a for loop
--> If it is positive, then return the sum as it is
--> If it is negative, then return 1/sum as the answer
-->But this is not an optimum approach, we can still simplify it

--> The optimum appraoch solves(doublt - mostly) the problem in O(log n)
--> Where we check the powers and act accordingly


optimum soln:

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long num = n;
        
        if(num < 0)
            num = (-1)*num;
        
        while(num != 0)
        {
            if(num % 2 == 1)
            {
                ans = ans * x;//if it is in odd power, write it in terms of that num * num in even powers and then reduce it by 1
                num = num - 1;
            }
            else
            {
                x = x * x;
                num = num / 2;//if it is even power then write in powers of 2 and divede by 2
            }
        }
        if(n < 0)
            ans = double(1.0)/double(ans);
        return ans;
        
    }
};



2.) Count good numbers

--> A string is good, if it has even numbers in even indexes and prime numbers in odd indexes where everything is 0 indexed
--> For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. 
--> constraints are: Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
  
Example 2:

Input: n = 4
Output: 400
  
  
Example 3:

Input: n = 50
Output: 564908303
  
  
  
--> need to revise again
--> Important link: https://www.youtube.com/watch?v=CctVpEGgNf0
--> takes logarithmic time complexity

# define mod 1000000007
class Solution {
public:         //even nos: 0, 2, 4, 6, 8 and prime nos: 2, 3, 5, 7
    
    long long power(long long x, long long y)
    {
        if(y == 0)// if y == 0, then x^y = 1
            return 1;// sor return 1;
        long long ans = power(x, y/2);//we are dividing the problem into pieces and checking the power if its excedding the limit
        ans = ans * ans; //(x, 6) = (x, 3)*(x, 3)
        ans = ans % mod;
        if(y % 2 == 1)//handling if the power is odd
        {
            ans = ans * x;//(x, 7) = (x, 3)*(x, 3)*x
        }
        ans = ans % mod;
        return ans;
    }
    
    int countGoodNumbers(long long n) { 
        long long odd = n/2;//the odd numbers of places are to be filled by prime numbers
        long long even = n/2 + n%2;// the even numbers are to be filled by the even numbers
        return (power(5, even))*(power(4, odd)) % mod;//there are 5 even numbers and 4 prime numbers b/w 0-9
         // and we are taking mod because it might go out of range
    }
};



3.) Sort a stack using recursion


Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
  
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

--> Important qs and need to revise again
--> Brute force approach is that first, store the elements of the stack into a container and then sort that container and then again insert elements 
from the container to the stack.
--> TC = O(N) + O(N log n)
--> Important link : https://www.youtube.com/watch?v=BmZnJehDzyU&t=3072s
  
  
void sortInsert(stack<int> &st, int num)
{
    if(st.empty() or st.top() < num) // if stack is empty or when stack is not empty and top is less then the number
        {
             st.push(num);//then we push the num into the stack
            return;   //then we return, that is we come out of the function
        } 
    int n = st.top();//make n the top of the stack
    st.pop();
    
    sortInsert(st, num);//we recursively call 
    
    st.push(n);//and push the n into the stack
        
}
void SortedStack :: sort()//the basic idea is to remove all the elements from the stack 
                          // and then insert in an sorted manner into the stack, 
                          //this function will juz juz pop the elements one by one 
{
    if(!s.empty())
    {
        int num = s.top();//it keeps track of the top most element in the stack
        s.pop(); //remove it from the stack
        
        sort();//keep doing this again and again untill the stack is epty
        
        sortInsert(s, num);// this function will insert the elements in sorted manner into the stack, which is the final answer
                           // the input to the function are stack s and the num that is to be inserted in sorted manner
    }                  
}



4.) Reverse a Stack


Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}

Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}

--> step 1: Put the stack's top element aside
    step 2: Use recursion to reverse the remaining stacks
    step 3: Insert the top element at the bottom insertAtBottom(stack.top()) 
      
--> TC : O(N^2) SC : O(N)
--> Important Resource: https://www.youtube.com/watch?v=BmZnJehDzyU&t=3072s

class Solution{
public:

    void insertAtBottom(stack<int> &St, int element)
    {
        //base case
        if(St.empty())
        {
           St.push(element);//if the stack is empty then push the element into the stack
           return ;
        }
        
        else
        {
            int num = St.top();
            St.pop();
            //recursive call
            insertAtBottom(St, element);//till this step, the stack becomes empty
                                    
            St.push(num);//and then topmost element is pushed into the stack
        }
    
    }
    
    void ReverseStack(stack<int> st)
    {
        //base case
        if(st.empty())//if stack is empty, then return
            return;
        
        else
        {
            int num = st.top();
            st.pop();
            
            //recursive call
            ReverseStack(st);
            
            insertAtBottom(st, num);//insert at bottom
            
        }
    }
    stack<int> Reverse(stack<int> St)
    {
        ReverseStack(St);
        return St;
    }
    
};

 

5.) Generate parantheses



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]


--> Important qs
--> Important link: https://www.youtube.com/watch?v=WW1rYrR3tTI
--> Conditions are : open < n && close < open and if string.size() == n * 2 that is if the no of brackets become equal, then push that string into the vector



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;//which is going to return the ans
        fnc(ans, n, 0, 0, "");//recursive function
        // we pass (ans, no. of pairs, initial open brackets, initial closing brackets, empty string)
        return ans;
        
    }
    
    void fnc(vector<string> &ans, int n, int open, int close, string s)
    {
        //base case
        if(s.size() == n * 2)
        {
            ans.push_back(s);//if the string size becomes n*2, then just add that string to the vector
            return;
        }
        
        //first condition
        if(open < n)//then insert opening bracket
            fnc(ans, n, open+1, close, s + "(");//open will be incremented by 1 and we will add ( to the string
        
        if(close < open)
            fnc(ans, n, open, close+1, s + ")");//close will be incremented by 1 and we will add ) to the string
        
        
    }
};




6.) 
