1.) Non Repeating Character - Easy


--> Solved using two traversal of the string but need to solve in another better approach
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char, int> mpp;//creating a unordered map to store the varable and count
        
        for(int i=0; i < S.size(); i++)
        {
            mpp[S[i]]++;//fuly traverse the string and increase the count iteratively
        }
        
        for(int i=0; i < S.size(); i++)
        {
            auto it = mpp.find(S[i]);//this itrator will used to find the count while the traversing the u map
            if(it->second == 1)//if count is 1, then return it
                return S[i];
        }
        return '$';//else return a NULL string
    }

};


2.) Check if two arrays are equal or not - Easy

--> Brute force approach is to sort both the arrays and check if the elements are equal iteratively TC = O(N Log N) and SC = O(1)
--> Other approach is maintain a map which stores the occuurences of characters
--> If we encounter a character in string 1, increase the count by 1 and if we encounter a character in string 2 decrease the count TC = O(N) and SC = O(N)
  
  
    
class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        if(A.size() != B.size())
            return false;
        
        unordered_map<char, int> mpp;//maintain a unordermap to count the occurence
        
        for(int i=0; i < N; i++)
        {
            mpp[A[i]]++;//if a character is encounter from the vector A increase the count by 1
        }
        int flag=0;
        
        for(int i=0; i < N; i++)
        {
            mpp[B[i]]--;//if a character is encounter from the vector B decrease the count by 1
        }
        
        for(auto it: mpp)
        {
            //if the count is not zero, means that two array are not equal, and there are some mismatch in two arrays
            if(it.second != 0)//if count is not 0, at any point
            {
                flag = 1;//make flag as 1 and then break out of the loop, 
                break;
            }
        }
        
        if(flag == 1)
            return false;
        return true;
    
    }
};
