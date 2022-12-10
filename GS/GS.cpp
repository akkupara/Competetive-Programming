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






3.) Remove Duplicates from sorted list:

case I: when neighbours are not equal, if not then juz move to the next node

case II: when neighbours are equal, then change the links
    
    
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *curr = head;
        while(curr->next != NULL)
        {
            if(curr->val != curr->next->val)// case I
                curr = curr->next;
            else
                curr->next = curr->next->next;// case II
        }
        return head;
    }
};



4.) Remove Duplicates from sorted list II 

https://www.youtube.com/watch?v=R6-PnHODewY

--> Given the head of a sorted linked list, delete all nodes that have duplicate numbers
--> leaving only distinct numbers from the original list.
    
    
    case I: when neighbours are not equal, move only prev pointer
    case II: when neighbours are equal, move only head pointer
    
    
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        
        while(head!=NULL)
        {
       
            if(head->next!=NULL && head->val==head->next->val)
            {
                while(head->next!=NULL && head->val==head->next->val)
                    head=head->next; // case II

                prev->next=head->next;
            }
            else if(head->next!=NULL && head->val != head->next->val)
                prev=prev->next; // case I


            head=head->next; // always move head 
        }
        
        return dummy->next;
    }
};


5.) Remove duplicates from an unsorted linked list

we are creating a hashmap and checking if that node is already present or not
    
case I: If that node is already present, then prev->next = curr->next, and then delete curr

case II: If that node is not already present, then inset it into set and make prev = curr

always make curr = prev->next


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> set;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL)
        {
            if(set.find(curr->data) != set.end()) // case I 
            {
                prev->next = curr->next;//change the link
                delete(curr);//delete the node
            }
            else
            {
                set.insert(curr->data);// case II
                prev = curr;
                
            }
            curr = prev->next; //only then it can point to the new curr after removal of node
        }
        return head;
    }
};



6.) Minimum Size Subarray Sum - two pointer and SLIDING WINDOW


--> Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. 
--> If there is no such subarray, return 0 instead.
    

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

    
    
--> move R, if values from L to R is less than target
--> move L, if values from L to R is greater than target


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;//left pointer
        int total = 0; //the total sum from L to R
        int res = 1e9;//answer which is the min length of the subarray
        
        for(int r=0; r < nums.size(); r++)
        {
            total += nums[r];
            while(total >= target)
            {
                res = min(res, r-l+1);
                total = total - nums[l];
                l++;
            }
        }
        
        if(res == 1e9)
            return 0;
        
        return res;
        
    }
};




8.) Minimum path sum

--> Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

--> You can only move either down or right at any point in time.
    

Recursion solution:

class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid)
    {
        if(i==0 && j==0)
            return grid[i][j];
        if(i < 0 || j < 0)
            return 1e9;
        
        int up = grid[i][j] + f(i-1, j, grid);
        int left = grid[i][j] + f(i, j-1, grid);
        
        return min(up, left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return f(n-1, m-1, grid);
    }
};




Tabulation:


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                        up = up + dp[i-1][j];
                    else
                        up = up + 1e9;
                    
                    int left = grid[i][j];
                    if(j>0)
                        left = left + dp[i][j-1];
                    else
                        left = 1e9;
                    
                    dp[i][j] = min(left, up);
                
                }
            }
        }
        return dp[n-1][m-1];
    }
};


10.) Index pair of a string

--> Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] 
is in the list of words.
    

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]



vector<vector<int>> indexPairs(string text, vector<string> &words)
{
    vector<vector<int>> res;
    
    for(int i=0; i < words.size(); i++)
    {
        int start = 0;
        auto pos = text.find(words[i], start);
        while(pos != string::npos)
        {
            res.push_back({pos, words.size()+pos-1});
            start = pos+1;
            pos = text.find(words[i], start);
        }
    }
    sort(res.begin(), res.end());
    
    return res;
}





11.) No. of mismatching bits

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











