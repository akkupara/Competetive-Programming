1.) Validate BST


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
