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



