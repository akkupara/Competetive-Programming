1.) Sort a stack using recursion

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



2.) Reverse a Stack

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


