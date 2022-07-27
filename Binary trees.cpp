Binary Tree Inorder Traversal

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

