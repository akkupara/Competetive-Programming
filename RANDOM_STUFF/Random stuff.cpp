1.) Counting bits

--> Given an integer n, return an array ans of length n + 1 
  such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
    
    
--> Observation to made in optimised approach is that in n and 2n(in binary form), the no of 1's are equal

    
--> 
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

  
--> Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101



Brute - O(N Log n)
  
  
  class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        
        for(int i=0; i <= n; i++)
        {
            int num = i;
            int count = 0;
            while(num)//traverse till num is not 0 and count the no of 1 is the binary number
            {
                
                count = count + num%2;//checking if the last bit is 1, if it is add it to the count i.e increment count by 1
                num = num /2 ;//equivalent to removing the last bit
            }
            ans[i] = count;
        }
        return ans;
    }
};




Optimised: O(N)


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        
        for(int i=0; i <= n; i++)
        {
            if(i % 2 == 0)//if i is even 
                ans[i] = ans[i/2];
            else//if i is odd
                ans[i] = ans[i/2] + 1;//11 / 2 = 5 ,    11 = 1011 and 5 = 101
        }
        return ans;
    }
  
};







2.) No. of mismatching bits

--> 
Input :  A = 12, B = 15
Output : Number of different bits : 2
  
Explanation: The binary representation of 
12 is 1100 and 15 is 1111.
  
So, the number of different bits are 2.
  
  
  
  
int numberOfMismatchingBits(int first, int second)
{
    int count = 0;
    for(int i=0; i < 32; i++)
    {
        if(((first >> i) & 1) != ((second >> i) & 1))
            count++;
    }
    return count;
}
