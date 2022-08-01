1.) Binary Tree Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st; // stack that is used to store all the nodes
        TreeNode* node = root; // creating a node and making it the root
        
        vector<int> inorder; // creating a vector to store the inorder traversal of the nodes
        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else//if the node == NULL
            {
                if(st.empty() == true) //checking if the stack is empty, if its empty then break
                    break;
                node = st.top();//when node = NULL, then make the node equal to topmost element in the stack
                st.pop(); // then print it and remove it from the stack
                inorder.push_back(node->val); //insert that node into the inorder vector
                node = node->right;//once the left value is printed then move to the rightside
                
            }
        }
        return inorder;//return the inoder vector which contains the inorder traversal of the given tree
        
        
    }
};



2.) Binary Tree PreOrder Traversal
    
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) //when root is null, then return empty vector
            return preorder;
        stack<TreeNode*> st;//creating a stack
        st.push(root);//first push the root
        
        while(!st.empty())// while stack is non empty
        {
            root = st.top();//making the top element of the stack as root
            st.pop();//and then poping it from the stack 
            preorder.push_back(root->val);//pushing that poped element into the vector
            
            if(root->right != NULL)
               st.push(root->right);//if the right node is not null, then put the  element into the stack
            
            if(root->left != NULL)
               st.push(root->left);//if the left node is not null, then put the  element into the stack
             
        //first we put the right node into the stack and then the left node becuase it is a stack LIFO
            
        }
        return preorder;
        
        
        
    }
};


3.) Maximum depth of a binary tree

class Solution {
public:
    int maxDepth(TreeNode* root) {//TC and SC is also O(n)
        if(root == NULL)
            return 0;
        int lh = maxDepth(root->left); //left height can be found
        int rh = maxDepth(root->right); //right height can be found
        
        return 1+max(lh, rh);
        
    }
};



4.) Check for balanced binary tree


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(height(root) != -1) // if the depth is not -1, then it is balace binary tree
            return true;
        return false;//if depth is -1, then it is not a balanced binary tree
        
    }
    
    int height(TreeNode* root)
    {
        if(root == NULL)//if root is NULL return 0
            return 0;
        
        int lh = height(root->left); //calculate the left height using the recursive call
        if(lh == -1) //if left height is -1 then return -1
            return -1;
        
        int rh = height(root->right);//calculate the right height using the recursive call
        if(rh == -1)////if left height is -1 then return -1
            return -1;
        
        if(abs(rh-lh) > 1)//if the difference between the left and right height is greater than 1, then it is not a balanced binary tree
            return -1;
        return 1+max(lh, rh);// this returns the heigth/depth of the binary tree
    }

};



