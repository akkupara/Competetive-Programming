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
  
  
