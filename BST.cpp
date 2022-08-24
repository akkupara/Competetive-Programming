1.) Search in a BST

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val)// we traverse the tree until the root is not null and until the we find the particular value
        {
            if(val < root->val)//this is the property of a BST
                //if the given val is less the root->val then we move left  
                root = root->left;
            else
                root = root->right;//if val > root->val, then move right
        }
        return root;//finally we return the root
    }
};


2.) Ceil in a BST

     10
    /  \
   5    12
  / \ 
 4   7
      \
       8
X = 6
Output: 7
  
  
X = 11
Output: 12
  
  --> given a value, we have to find the ceil of the BST
  --> ceil value is the closest largest value in the BST i.e we have to find a value that is greater than the given input value
  --> TC = log(n) which is the height of the tree
  
  
  int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ceil = -1;
    
     while(root == NULL)//we keep on traversing until the node value becomes NULL
     {
         if(root->data == input)//if the given is already present in the BST, then make it the ceil and return it
         {
             ceil = root->data;
             return ceil;
         }
         else if(root->data > input)//if the key is less than the root->data, then we move lefr
            {
                ceil = root->data;//make ceil as the root->data 
                root = root->left;//and then move left
            }
            
        else if(input > root->data)//if the key is more than the root->data, then we move right
        {
            
            root = root->right;//we move right
        }
     }
     return ceil;
    
}



3.) Floor in a BST

--> Floor in a BST is the largest that is smaller than or equal to given input
-->    10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 11(largest value that is closest and less than 13)
  

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    //Your code here
        if (root == NULL) return -1;
    
    int floor = -1;
    
     while(root)//we keep on traversing until the node value becomes NULL
     {
         if(root->val == X)//if the given is already present in the BST, then make it the floor and return it
         {
             floor = root->val;
             return floor;
         }
         else if(root->val > X)//if the key is less than the root->data, then we move lefr
            {
                
                root = root->left;//and then move left
            }
            
        else if(X > root->val)//if the key is more than the root->data, then we move right
        {
            floor = root->val;//make the floor = root->val
            root = root->right;//we move right
        }
     }
    
     return floor;
    
}



4.) Insert a Node in a BST



--> TC = O(log n)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)//if the tree is NULL, then insert that node into the tree
        {
            return new TreeNode(val);//this is the syntax for inserting the node into the tree
        }
        TreeNode* cur = root; //we create a copy of the root, becoz at the end we have to return the root itself
        
        while(true)
        {
            if(cur->val <= val)//if the cur->val is less than val, then we move right
            {//now there are two options, 
                if(cur->right != NULL)//one is, if cur->right is not NULL, then we move more rightwards
                    cur = cur->right;
                else
                {
                    cur->right = new TreeNode(val);//if it is not NULL, then insert that node into the tree
                    break;
                }
            }
            else//if cur->val is greater than val, then we move left
            {
                if(cur->left != NULL)//one is, if cur->left is not NULL, then we move more leftwards
                    cur = cur->left;
                else{
                    cur->left = new TreeNode(val);//if it is not NULL, then insert that node into the tree
                    break;
                    
                }
            }
        }
        return root;
    }
};




5.) Delete a node in a BST


--> needs a lot of revision

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)//if the tree is empty, then return NULL
            return NULL;
        if(root->val == key)//if it is the root that has to be deleted,
            return helper(root);
        
        TreeNode* dummy = root;//we are creating a copy of the root, so that it will not be destroyed
        while(root != NULL)//we have to traverse until the node is not NULL
        {
            //this if condition is for the left sub-tree
            if(root->val > key)//if root->val > key, then we move leftwards in the tree//this is for the left sub-tree
            {
                if(root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);// if root->left->val == key, we then make the connection change using the helper function
                    break; //and then break, because our job is done
                }
                else
                    root = root->left;//else we move leftwards in the tree
                    
            }
            else//this is for the right subtree
            {
                if(root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);// if root->right->val == key, we then make the connection change using the helper function
                    break; //and then break, because our job is done
                }
                else
                    root = root->right;//else we move rightwards in the tree
            }
        }
        return dummy;
    }
        
        
        TreeNode* helper(TreeNode* root)
        {
            if(root->left == NULL)//if root->left is NULL, then we connect the root->left to the new root->right
                return root->right;
            else if(root->right == NULL)
            {
                return root->left;
            }
            
            TreeNode* rightChild = root->right;//we keep the right child at one point
            TreeNode* lastRight = findLastRight(root->left);// we keep on traverse to the right and mark at it that point
            lastRight->right = rightChild;//we make the lastright->right = rightchild and the connection is made
            return root->left;
        }
        
        TreeNode* findLastRight(TreeNode* root)
        {
            if(root->right == NULL)
                return root;
            return findLastRight(root->right);
        }
};
    


6.) Kth smallest element in the BST



Input:

      2
    /   \
   1     3

K = 2
Output: 2
    
    
--> we can do a DFS traversal, by storing all the nodes into a vector and then sorting it to find the kth smallest element, but that would have the 
--> TC = O(N)- for tree traversal + O(N logN)- for sorting the vector
--> An interesting property is that "Inorder traversal of any given BST is always in sorted order", so in this approach we can avoid the Nlogn -sorting extra TC but still we are using extra space of O(N
--> can we do it better, yes whenever we visit a node in preorder manner, we kkep a counter and increase it whenever we visit a node, whenever the value of counter is equal to K, we return the node's value at which we are currently standing


__> if we do recusrive traversal, then TC = O(N) and SC = O(N)
__> if we do iterative traversal, then TC = O(N) and SC = O(N)
__> if we do Morris Traversal, then TC = O(N) and SC = O(1)
__> same is for the kth largest element, where we check for the counter == size-k, and then return that node->val


--> This is the recursive solution


class Solution {
public:
    int count = 0, ans;
    void inOrder(TreeNode* root, int k)
    {
        if(root == NULL)
            return;//it exits the function immediately
        inOrder(root->left, k);// first we traverse to the left and then right since it is the inorder traversal
        
        if(++count == k)// if the count is equal to the given k 
        {
            ans = root->val;//make the sum as the root->val 
            return;//then it exits the function immediately
        }
        
        inOrder(root->right, k); // we traverse to the right
    }
    int kthSmallest(TreeNode* root, int k) {
        
        inOrder(root, k);
        return ans;
        
    }
};



7.) LCA in BST

              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7

    
class Solution {
public://iterative solution
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            if(root->val > p->val && root->val > q->val)g//if the two given nodes are less than the node at which we are standing currently then we move to the left
                root = root->left;
            else if(root->val < p->val && root->val < q->val)//if the two given nodes are greater than the node at which we are standing currently then we move to the right
                root = root->right;
            else return root;//if not then we return the root
        }
        
        return NULL;
    }
};



8.) Inorder Successor in a BST


--> It is the next node in sorted order
--> Inorder successor of a node is the next node in Inorder traversal of the Binary Tree


Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
                 
K(data of x) = 8
Output: 10
Explanation:
Inorder traversal: 4 8 10 12 14 20 22
Hence, successor of 8 is 10.
    
    
    
    
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = NULL;//initially making the successor node as NULL
        
        while(root != NULL)//we traverse until the root is NULL
        {
            if(x->data >= root->data)//if the value to searchded is greater than the root->node
                root = root->right;//then we move right
            else 
            {
                succ = root;///or else we move left and store the root in succ
                root = root->left;
            }
        }
        return succ;
    }
};


9.) Two Sum in BST

--> it can be solved by converting the bst into an array and then solve it like the two sum problem and TC = O(N)+O(N)
--> But this can be optimised, using BST iterator which i didnt solve still



THIS IS THE RECURSIVE SOLN>>>>>
class Solution {
public:
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        
        if(root == NULL)//if root is NULL, then return false
            return false;
        
        if(s.count(k - root->val) != 0)// it does a pre order traversal and iterative chacks whether k-root->val is already present in the set, if it is present it return true, else traverse the whole tree and check further
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
        
    }
    
};


10.) Recover BST

--> Brute force is to do the inorder traversal and then sort and store it an DS but now traverse the actual tree and compare the sorted DS 
and the actual traversal and swap the two nodes 

--> TC = O(N) + O(N lOG N)
--> But this can be done better











