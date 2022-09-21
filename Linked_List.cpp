1.) linked list Insertion

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node* newNode = new Node(x);//creating new node with given data
       
       if(head == NULL)//if NULL, return the newNode that we created
            return newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node* newNode = new Node(x);//creating a new node with give data
       Node* temp = head;
       
       if(head == NULL)
            return newNode;
            
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newNode;
        return head;
        
    }
};


2.) Deleting a given Node

--> Easy qn
--> https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/
  
  

class Solution {
public:
    void deleteNode(ListNode* node) {//in this qs, we are juz given only the node and not head, so we need to juz delete the given node
        
        node->val = node->next->val;//we change the value of the node to the next node's val and change the link but this only deletes the value of the node but not the address of the node
        node->next = node->next->next;
        
    }
};




3.) Count nodes of linked list

--> Easy Qs

class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head)
    {
        int count = 0;
        Node* temp = head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
    return count+1;
    
    }
};


4.) Middle node of the linked list

--> brute approach is to find the middle using count and then traversing till the count and return the node where count == mid
--> takes O(N) + O(N/2)
--> But can solved by tortoise approach which uses two pointer(slow and fast)
--> Slow pointer moves by 1 position and fast by 2 postion, 
--> When fast pointer reaches the last node or crosses the boundary, the slow pointer would point to the middle of the linked list

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]



class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL)//until fast in NULL or fast->next is NULL, keep moving
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
};



5.) Reverse Linked List Iteratively

--> Important qs and need to revise again
--> Tc = O(N) and SC = O(1)
  
 
 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;//creating a dummy node, new head which we are going to return at the end
        while(head != NULL)
        {
            ListNode* next = head->next;//create a node which points to immidiate next node of the head
            head->next = newHead;//this line changes the forward link to backward link, now head->next points towards the dummy node
            newHead = head;//make the dummy node point to the head
            head = next;//make head as the next
        }
        return newHead;
    }
};




6.) Detect Cycle in Linked List

--> Brute force approach is that create a hash table and insert the complete node into the hash table, if we visit a already visited node, then we can return that a cycle exists
--> but this approach uses TC = O(N) and SC = O(N) but problem with this approach is it uses extra O(N) space
--> Better approach is using a two pointers(fast and slow), where slow moves by 1 and fast moves by 2
--> If there exists a cycle, then at one point, slow and fast pointer will collide
--> If at some point, if the fast pointer reaches NULL, then we can say no cycle exists


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)//if the head or head->next is null, then no cycle exits
            return false;
        
        ListNode* slow = head;//both slow and fast pointer point to the head 
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)//until fast->next and fast->next->next reaches NULL
        {
        
            slow = slow->next;//move the slow pointer by 1 step
            fast = fast->next->next;//move the fast pointer by 2 steps
            
            
            if(slow == fast)//if slow and fast pointer collides, then cycle exits
                return true;
        }
        return false;
    }
};



7.) Starting point of the cycle in Linked list

--> Same as the above qs 
--> first, we find whether cycle exists or not, a point comes where fast and slow pointers collide
--> We take another pointer (entry) starting from the beginnning, now we move slow and entry by 1 
--> At some point, slow and entry pointer collides, which points to the starting point of the cycle

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next != NULL  && fast->next->next != NULL)//we traverse until fast->next and fast->next-> not equal to NULL
        {
            fast = fast->next->next;//move fast by 2 steps
            slow = slow->next;//move slow by 1 step
            
            if(slow == fast)// if slow and fast collide
            {
                while(slow != entry)//exit the loop once slow and entry collides
                {
                    slow = slow->next;//move slow by 1
                    entry = entry->next;//move entry by 1
                }
                return slow;//when slow and entry collides, slow and entry will be pointing to the starting position of the loop
            }
        }
        return NULL;//else return NULL
        
    }
};




8.) Find length of the loop

--> Same as the above qs
--> but when slow and fast collides, we keep the fast as it is, and moves slow by 1 iteratively until it again collides with fast, each time increasing the count by 1
--> Finally return the count, else return 0
  
  
int countNodesinLoop(struct Node *head)
{
    int count = 1;
    if(head == NULL || head->next == NULL)
            return NULL;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != NULL  && fast->next->next != NULL)//we traverse until fast->next and fast->next-> not equal to NULL
        {
            fast = fast->next->next;//move fast by 2 steps
            slow = slow->next;//move slow by 1 step
            
            if(slow == fast)// if slow and fast collide
            {
                slow = slow->next;//once slow and fast collides, move left by 1 
                while(slow != fast)//and as long slow == fast, move left and increase count by 1
                {
                    slow = slow->next;//move slow by 1
                    count++;;//increase count by 1
                }
                 return count;//return count
            }
        }
        
    return 0;//else return 0
    
}




9.) Check if a Linked List is a Palindrome or not
  
--> This is the brute force approach where we will enter all the linked list nodes into the vector and find if the vector is a palindrome or not
--> But this takes TC = O(N) and SC = O(N) + O(N)
  
--> Can be optimised further
--> optimal approach is that we find the middle of the linked list(if n is even, we take left as the middle node)
--> and after that node, we reverse it and move slow by 1 to the right 
--> and also we keep a dummy pointer to the begn of the linked list and move both pointers and check if they are equal iteratively






Brute Approach:

class Solution {
public:
    bool isPalindrome(ListNode* head) {//this is the brute force approach where we will enter all the linked list nodes into the vector and find if the vector is a palindrome or not
        ListNode* temp = head;//create a temp node to traverse
        vector<int> ans;//vector to store the linked list elements
        int flag = 0;
        
        ans.push_back(head->val);//first push the head->val
        while(temp->next != NULL)//traverse untill we reach the last node
        {
            temp = temp->next;//move to the next node each time
            ans.push_back(temp->val);//push the node's value in to the vector
        }
        int n = ans.size();
        
        for(int i=0; i <= ans.size()/2 && n != 0; i++)//run the loop till half of the vector
        {
            if(ans[i] != ans[n-i-1])//this condition is to check if it is palindrome or not
            {
                flag = 1;//if it not equal at some point, then make flag as 1 and then break
                break;
            }
        }
        
        if(ans.size() == 1)//if only one exists, return true
            return true;
        if(flag == 1)//if flag is 1, then it is not a plaindrome
            return false;
        else//if flag is , then it is a palindrome
            return true;
        
    }
};




Optimised approach:



class Solution {
public:
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* next = NULL;
        ListNode* pre = NULL;//dummy node
        
        while(head != NULL)
        {
            next = head->next;//create a node which points to immidiate next node of the head
            head->next = pre;//this line changes the forward link to backward link, now head->next points towards the dummy node
            pre = head;//make the dummy node point to the head
            head = next;//make head as the next
        }
        return pre;//this will act as the new head, so we return it
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)//if the linked list has only one node or no nodes at all
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);//we reverse the linked list starting from slow->next i.e connecting the reversed right half to the slow->next
        slow = slow->next;//slow will be pointing to the 
        
        while(slow != NULL)//we move till slow reaches NULL
        {
            if(head->val != slow->val)//check if head's val and slow's val
            {//if they are not equal, then 
                return false;
            }
            head = head->next;//move head by 1 
            slow = slow->next;//move slow by 1
            
        }
        return true;
    }
    
    
};



10.) Odd Even linked list


-->segregate odd nodes followed even node and we are not talking about value of the nodes i.e all the odd index nodes should occur first followed by even index nodes
--> make an odd ll and an even ll, then connect the odd with the even and then return the odd-head.

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]


Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddh = NULL;
        ListNode* oddt = NULL;
        ListNode* evenh = NULL;
        ListNode* event = NULL;
        
        int count = 1;//keeps track of the index, as it start from 1
        while(head != NULL)
        {
            if(count % 2 == 0)
            {
                if(evenh == NULL)//even linked list is empty
                {
                    evenh = head;//since the ll is empty, even-head and even-tail both will point to that single node
                    event = head;
                    head = head->next;//move head to the next 
                }
                else//means the even ll is not empty, i.e there is something in the linked list
                {
                    event->next = head;//make the 
                    event = event->next;//even tail should be updated
                    head = head->next;//move head ahead
                }
                count++;

            }
            else
            {
                if(oddh == NULL)//even linked list is empty
                {
                    oddh = head;//since the ll is empty, even-head and even-tail both will point to that single node
                    oddt = head;
                    head = head->next;//move head to the next 
                }
                else//means the even ll is not empty, i.e there is something in the linked list
                {
                    oddt->next = head;//make the 
                    oddt = oddt->next;//even tail should be updated
                    head = head->next;//move head ahead
                }
                count++;//becuz we have to go to next index
            }
        }
        
        if(oddh == NULL)
            return evenh;
        if(evenh == NULL)
            return oddh;
        
        event->next = NULL;
        oddt->next = evenh;
        
        return oddh;
            
        
    }
};




11.) Remove Nth Node From End of List


Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]


Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]



--> dummy node's next will point to the head
--> basic intuition is having two pointers, fast and slow pointing to the dummy node
--> first move the fast pointer by n(given) positions
--> //traverse untill we fast->next is NULL and move slow and fast by 1 simultaneously
--> When fast->next is NULL is reached, then slow->next is the node to be deleted,
--> then we change the link


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;//dummy node's next will point to the head
        
        
        //basic intuition is having two pointers, fast and slow pointing to the dummy node
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        for(int i=1; i <= n; i++)//first move the fast pointer by n(given) positions
            fast = fast->next;
        
        while(fast->next != NULL)//traverse untill we fast->next is NULL
        {
            fast = fast->next;//move fast by 1
            slow = slow->next;//move slow by 1
        }
        
        slow->next = slow->next->next;//break the link and make the new link
        
        return dummy->next;//return dummy->head, because that is where head of the ll is....
    }
};
