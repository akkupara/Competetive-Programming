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


vvImp QS) Rotate list


--> Given the head of a linked list, rotate the list to the right by k places.
 
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(!head  || !head->next || k == 0)//if 0 node or 1 node or even when k is 0, return the head itself
            return head;
        
        
        //count the no of nodes
        ListNode* cur = head;
        int len = 1;
        while(cur->next != NULL)
        {
            cur = cur->next;
            len++;
        }
        
        
        cur->next = head;
        k = k % len;
        k = len - k;//go till that node
        
        while(k != 0)
        {
            cur = cur->next;
            k--;
        }
        
        head = cur->next;//change the link
        cur->next = NULL;
        
        return head;
        
        
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



12.) Delete the middle node of the Linked List

--> We maintain three pointers fast, slow, prev, keeping the prev node to get the previous node of slow pointer when we reach middle
--> we move the slow by 1 and fast by 1 and when slow != head, we move prev by 1, since we want prev to start one step later than slow node
--> and changing the links to prev and deleting slow and returning the head will give us the answer.
  
  
  
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;//keeping this prev node to get the previous node of slow pointer when we reach middle
        
        if(head == NULL)//if the Linked list is empty
            return NULL;//return NULL
        
        if(head->next == NULL)//if the linked list has only one node
        {
            delete(head);//then delete that node and return NULL
            return NULL;
        }
        
        while(fast != NULL && fast->next != NULL)
        {
            if(slow != head)//since we want prev to start one step later than slow node
                prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        delete(slow);
        
        return head;
    }
};



13.) Sort a Linked List

1. Using 2pointer / fast-slow pointer find the middle node of the list.
2. Now call mergeSort for 2 halves.
3. Merge the Sort List (divide and conqueror Approach)
  
--> https://leetcode.com/problems/sort-list/discuss/1795126/C%2B%2B-oror-Merge-Sort-oror-2-Pointer-oror-Easy-To-Understand
--> https://www.youtube.com/watch?v=rM5EEA_rbNY


//MergeSort Function O(n*logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)//If List Contain a Single or 0 Node
            return head;
        
        ListNode *temp = NULL;//create a dummy node
        ListNode *slow = head;
        ListNode *fast = head;
        
        //2 pointer turtle approach
        while(fast != NULL && fast->next != NULL)//here we are finding the middle node after which we are dividing into two halves and then sorting them separately
        {
            temp = slow;//now temp points to slow and each iteration temp becomes where slow points to 
            slow = slow->next;//in last iteration slow would be poiting to the head of the right half
            fast = fast->next->next;
        }
        
        //now temp will pointing to the last element of the left half, i.e the mid
        temp->next = NULL;//end of first
        
        ListNode *left = sortList(head);    //left half recursive call
        ListNode *right = sortList(slow);    //right half recursive call
        
        return mergeList(left, right);
        
    }
    ListNode* mergeList(ListNode *left, ListNode *right)
    {
        ListNode *ptr = new ListNode(0);//creating a dummy node with value 0;
        ListNode *curr = ptr;//another node which points to ptr
        
        while(left != NULL && right != NULL)//till both of them reaches NULL
        {
            if(left->val <= right->val)
            {
                curr->next = left;//curr should be linked to left
                left = left->next;//move iteratively
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;//moving curr to next position
        }
        
        //for unequal left and right halves
        if(left != NULL)//if right halves is over 
        {
            curr->next = left;//curr should be linked to left
            left = left->next;//move iteratively
        }
        
        if(right != NULL)//if left half is over
        {
            curr->next = right;
            right = right->next;
        }
        return ptr->next;//because that's where head of the LL starts  
    }
};



14.) Given a linked list of 0s, 1s and 2s, sort it.
  
--> one approach is finding the counts of 0, 1, 2 and then running a loop till the individual count becomes 0, then putting the values in order
--> This does not change the links but changes only the value of each node


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int zeroc = 0;
        int onec = 0;
        int twoc = 0;
        
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == 0)
                zeroc++;
            else if(temp->data == 1)
                onec++;
            else if(temp->data == 2)
                twoc++;
                
            temp = temp->next;//moving temp to next position
        }
        
        temp = head;//make temp point to head
        
        while(temp != NULL)
        {
            if(zeroc != 0)
            {
                temp->data = 0;
                zeroc--;
            }
            else if(onec != 0)
            {
                temp->data = 1;
                onec--;
            }
            else if(twoc != 0)
            {
                temp->data = 2;
                twoc--;
            }
            temp = temp->next;////moving temp to next position
        }
        return head;
    }
};


optimised approach by changing the links:

--> Maintain 6 pointers and keep eaxch value in separate list and finally merge them

class Solution
{
    public:
    
    void insertAtTail(Node* &tail, Node* curr)
    {
        tail->next = curr;//creates a link b/w tail and curr
        tail = curr;//make tail point to curr
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zeroHead = new Node(-1);//creating new node with dummy value -1
        Node* zeroTail = zeroHead;//will point to xeroHead
        
        Node* oneHead = new Node(-1);//creating new node with dummy value -1
        Node* oneTail = oneHead;//will point to oneHead
        
        Node* twoHead = new Node(-1);//creating new node with dummy value -1
        Node* twoTail = twoHead;
        
        Node* curr = head;//create a temporary node and point to head;
        
        //create separate LL for 0, 1, 2 respectively
        while(curr != NULL)
        {
            int value = curr->data;
            
            if(value == 0)
            {
                insertAtTail(zeroTail, curr);//anyway we are going to insert the node from backside and node to be inserted is curr
            }
            else if(value == 1)
            {
                insertAtTail(oneTail, curr);
            }
            else if(value == 2)
            {
                insertAtTail(twoTail, curr);
            }
            curr = curr->next;
        }
        
        //merge 3 sublist
        if(oneHead->next != NULL)//checking if first list(1's list) is empty or not
        {
            zeroTail->next = oneHead->next;//becuase it should not be connected with dummy node, bu
        }
        else
            zeroTail->next = twoHead->next;//if the first list is empty then connect it directly with the second list
            
        oneTail->next = twoHead->next;//connect(1's list) to (2's list)
        twoTail->next = NULL;
        
        
        head = zeroHead->next;//make head point to zeroHead->next
        
        //delete dummy nodes
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return head;
    }
};



15.) Intersection of two Linked List - https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34

--> Brute force approach is keeping a node in LL1 as reference and checking if there is any node with the same address in LL2, but this takes TC = O(N*M)
--> can be optimised by using hash table where the complete node's address is being is hashed, this takes TC = O(M + N) and SC = O(N)
--> Can further be optimised, there are two similar approaches, once with lengthier code and other has a shorter code.
--> the idea of the shorter code, is make two dummy node point to two LL simultaneosly
--> traverse each other iteratively, untill one of the node reaches NULL, make that point to the beginning of the other LL.
  --> once the other dummy node reaches NULL, make that point to the head of the other dummy node.
 --> now traverse each of them together, where they collide is the intrsc of LL
 
 
 class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* a = headA;//we make the dummy node point to the head of LL-A
        ListNode* b = headB;//we make the dummy node point to the head of LL-B
        
        while(a != b)
        {
            if(a == NULL)//once u reach NULL, point to the other LL's starting
                a = headB;
            else
                a = a->next;//else move next
            
            if(b == NULL)
                b = headA;
            else
                b = b->next;
                
        }
        return a;
    }
};


16.) Add two numbers in two Linked List

--> only one approach which is the optimised approach

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();//create a dummy node linked list to store the answer
        ListNode* temp = dummy;//make a temp node to point to the head of the dummy linked list
        //and this temp is gonna iterate through the dummy linked list
        int carry = 0;//make carry as 0, which is gonna store the carry of the sum

        while(l1 != NULL || l2 != NULL || carry != 0)//iterated till we reach either ends of the LLs or till the carry becomes 0
        {
            int sum = 0;//initialse sum as 0, which is going to store the sum of the LLs
            if(l1 != NULL)
            {
                sum = sum + l1->val;//if l1 is not NULL, then add that nodes's value to the sum
                l1 = l1->next;//move to the next in LL l1
            }

            if(l2 != NULL)
            {
                sum = sum + l2->val;//if l1 is not NULL, then add that nodes's value to the sum
                l2 = l2->next;//move to the next in LL l1
            }
            sum = sum + carry;//add carry to sum
            carry = sum / 10;// we get carry by doing integer dvision of sum and 10
            ListNode* node = new ListNode(sum % 10);//create a node and add the sum%10 to it 
            temp->next = node;//make temp's next as node
            temp = temp->next;//move temp next iteratively as we traverse through the 
        }
        return dummy->next;//since dummy->next would be the starting of the new LL


    }
};



17.) Merge two sorted Linked List

--> There are two approaches, to sort it using external space and the other technique is to do it in-place
--> TC = O(M + N) and SC = O(1) -----> for in-place(optimised)
  
  
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)//if the first linked list is empty, then return the second linked list
            return l2;
        
        if(l2 == NULL)//if the second linked list is empty, then return the first linked list
            return l1;
        
        if(l1->val > l2->val)//we want the linked list to start from l1, so l1 should have the smaller value
            std::swap(l1, l2);//so we swap it so that linked list starts from l1
        
        ListNode* res = l1;//now, since l1 has minimum value, res points to l1
        
        while(l1 != NULL && l2 != NULL)
        {
            ListNode* temp = NULL;//we create a temp and assign to NULL each time
            while(l1 != NULL && l1->val <= l2->val)//as long as l1->val is less than l2->val, stay in LL1 itself
            {
                temp = l1;//assign the val of l1 to temp each iteration
                l1 = l1->next;//move iteratively
            }
            //when the value of l1->val > l2->val, it breaks out of the loop
            temp->next = l2;//change the links
            
            std::swap(l1, l2);//always the smaller element should be in l1, so we swap it
        }
        return res;
    }
};
  
 

18.) Add 1 to a number represented as linked list

-->there are two cases
-->One if the last digit is not a 9, so we juz change the last node value by 1
-->if the last node value is 9, then we do it differently
-->we first reverse it, add 1 to the right most node and we finally reverse the result



class Solution
{
    public:
    
    Node* Reverse(Node *head)
    {
        Node* curr = head;//current pointer
        Node* prev = NULL;
        Node* next;
        
        while(curr != NULL)//we traverse till current is not NULL
        {
            next = curr->next;//storing next node
            curr->next = prev;//changing the link backwards
            prev = curr;//prev gets updated
            curr = next;//curr gets updated
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        //if the last digit is not 9, we just simple return by adding 1, 
        //if the last digit is 9, we slove it differently
        
        head = Reverse(head);//we reverse the Linked List
        Node* current = head;//point to the head of the reversed List
        
        int carry = 1;
        
        while(carry != 0)
        {
            current->data = current->data + 1;//we add 1 to the data part
            if(current->data < 10)//if it is less than ten, juz reverse it again, and return it
                return Reverse(head);
            else
                current->data = 0;//if the sum is 10, then we make it zero and take the carry rightwards;
                
                
            if(current->next == NULL)//if it is the end of the list, we break from the loop
                break;
            else
                current = current->next;//move current to the next node where carry will still be 1
        }
        current->next = new Node(1);//if carry exceeds the size of the linked list
        return Reverse(head);
    }
};
