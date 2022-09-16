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
