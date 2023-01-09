1.) Validate BST (Range of Values)


--> Given the root of a binary tree, determine if it is a valid binary search tree (BST).

  
  TC = O(N) and SC = O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
        
    }
    
    bool isBST(TreeNode* root, long minval, long maxval)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= minval || root->val >= maxval)
            return false;
        
        return(isBST(root->left, minval, root->val) &&
               isBST(root->right, root->val, maxval));
    }
};




2.) LCA of BST

--> Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

--> The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants

TC = O(Height of tree) and SC = O(1) but recursive will take rss


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        
        int cur = root->val;
        
        if(cur < p->val && cur < q->val)//move right
            return lowestCommonAncestor(root->right, p, q);
        
        if(cur > p->val && cur > q->val)//move left
            return lowestCommonAncestor(root->left, p, q);
        
        return root;
    }
};




3.) Height of Binary tree/ Maximum depth of binary tree




class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh, rh);
    }
};




4.) Maximum sum path in binary tree

--> The path sum of a path is the sum of the node s values in the path.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxDownPath(root, maxi);
        return maxi;
    }
    
    int maxDownPath(TreeNode* root, int &maxi)
    {
        if(root == NULL)
            return 0;
        
        int left = max(0, maxDownPath(root->left, maxi));
        int right = max(0, maxDownPath(root->right, maxi));
        
        maxi = max(maxi, left+right+root->val);
        
        return max(left, right) + root->val;
    }
};



5.) Convert binary tree to linked list

--> There are three approaches using recursion, stack and morris traversal - most optimal

--> need to revise the other two approaches


https://www.youtube.com/watch?v=sWf7k1x9XR4


class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
        
    }
};





6.)  Minimum Depth of a Binary Tree

--> minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. 

    
            1
          /   \
         3     2
        /
       4           

Output: 2
    
    
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)//when the tree is empty return 0 since, the depth is zero
            return 0;
        if(root->left == NULL && root->right == NULL)//when the tree has only one node,
            //then obviously the depth of the tree will be 1
            return 1;// so we return 1 as the maximum depth
        
        int lh, rh;//we declare the right and left height
        
        if(root->left != NULL)//if left node is not NULL, then recursively travel to the left
        {
            lh = minDepth(root->left);// do the recursive call to root->left(other left nodes)
        }
        else
            lh = INT_MAX;// if root of the left is NULL, then make it INT_MAX
        
        
        if(root->right != NULL)//if right node is not NULL, then recursively travel to the right
        {
            rh = minDepth(root->right);// do the recursive call to root->right(other right nodes)
        }
        else
            rh = INT_MAX;//if right of the root is NULL, then make it INT_MAX
        
        
        return 1 + min(lh, rh);
        
    }
};




7.) Level order Traversal of a Binary Tree

Input:
        10
     /      \
    20       30
  /   \
 40   60
          
          
Output:10 20 30 40 60
  
  
  

--> The idea is to maintain a queue and a vector-of-vector which returns the ans


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;//the DS which stores the ans
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);//always push the root at the beginning
        
        while(!q.empty())//we iterate untill the queue becomes empty
        {
            int n = q.size();//size of the queue
            vector<int> level;//stores the ans for that level
            for(int i=0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();//we first pop the node from the queue
                
                if(node->left != NULL)//we first push left
                    q.push(node->left);
                
                if(node->right != NULL)//we then push right
                    q.push(node->right);
                
                level.push_back(node->val);//put that node into level DS
                
            }
            ans.push_back(level);//push that level traversal into ans DS
        }
        return ans;
    }
};



  
  
