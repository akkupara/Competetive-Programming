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

