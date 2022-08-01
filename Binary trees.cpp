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
 


5.) Diameter of a binary tree


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diameter(root, maxi);
        return maxi;
    
    }
    
    int diameter(TreeNode* root, int& maxi)
    {
        if(root == NULL)
            return 0;
        int lh = diameter(root->left, maxi);
        int rh = diameter(root->right, maxi);
        
        maxi = max(maxi, lh+rh);
        
        return 1 + max(lh, rh);
    }
};


6.) Determine if Two Trees are Identical


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
           return (p==q);
         return(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};



7.) Top view of the binary tree


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; // create a vector to store the top view of the binary tree
        if(root == NULL)
            return ans;
        map<int, int> mpp;//this map stores the (line-->node) first element in that line, but map stores only the first node in that particular line
        queue<pair<Node*, int>> q;//this queue contains (node, line), visits all the element in level order and puts these nodes along with their line number
        q.push({root, 0});
        
        while(!q.empty())
        {
            auto it = q.front(); //it gets the top most node
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            if(mpp.find(line) == mpp.end())//if that node is not in the map, then add it into the map
                mpp[line] = node->data;
                
            if(node->left != NULL)//if left node is not null
                q.push({node->left, line - 1});//then move to the left and make the line-1
            
            if(node->right != NULL)
                q.push({node->right, line + 1});
        }
        //then move to the right and make the line+1
            
            for(auto it: mpp)
            {
                ans.push_back(it.second);
            }
            return ans;
       
        
    }

};


8.) Maximum sum path ------ Hard Question

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxipath(root, maxi);
        
        return maxi;
        
    }
    int maxipath(TreeNode* node, int &maxi)
    {
        if(node == NULL)
            return 0;
        int left = max(0, maxipath(node->left, maxi));
        int right = max(0, maxipath(node->right, maxi));
        
        maxi = max(maxi, node->val+left+right);
        
        return node->val + max(left, right);
        
    }
};


9.) Right view of the binary tree

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);// we pass the root, level as 0 and the vector which is to be returned
        return res;
        
    }
    void recursion(TreeNode* root, int level, vector<int> &res)
    {
        if(root == NULL)//if root is null, we just return
            return;
        if(res.size() == level)//if size of the vector is equal to the level then we push that particular value of the node into the vector
            res.push_back(root->val);
        recursion(root->right, level+1, res);//we move to the right side first since we want the right view and do it recursively
        recursion(root->left, level+1, res);//we move to the left side and do it recursively
    }
};



10.) Left view of the binary tree


void recursion(Node* root, int level, vector<int> &res)
{
    if(root == NULL)
        return;
    if(res.size() == level)
        res.push_back(root->data);
    recursion(root->left, level+1, res);
    recursion(root->right, level+1, res);
    
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    recursion(root, 0, res);
    return res;
   
}


11.) Bottom left tree value

class Solution {
public:

    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q; // create a queue in which we are going to store the elements of the level order traversal
        q.push(root);//first we push the root of the tree into the queue
        
        while(!q.empty())
        {
            root = q.front();//now root is the front element in the queue
            q.pop();
            
            if(root->right)// we start from the right because by doing level order traversal from right to left we have the last traversed node as the left side node
                q.push(root->right);
            
            if(root->left)// we also visit the left node
                q.push(root->left);
            
        }
        return root->val;//at last only the left most bottom element will be present in the queue, we then make it the root and return its value
        
    }
    

};


12.) Symmetric Tree


class Solution {//the whole crux of mirror image is, when we visit a node, we check the root node's left with root node's right because of mirror image property 
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)//if the root is NULL then return true
            return true;
        return isSymmetricTrue(root->left, root->right);//this will return the value by travelling to left and right of the root
        
    }
    bool isSymmetricTrue(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)// if p and q both are null then return true
            return true;
        else if(p == NULL || q == NULL)
            return false;// if only one of them is NULL and the other is not
        else if(p->val != q->val)//checking if the value of p and q are same or not
            return false;// if not same then return false
        
        else
            return isSymmetricTrue(p->left, q->right)//we check the p's left with the q's right
            &&     isSymmetricTrue(p->right, q->left);//we check the p's right with the q's left
    }
};



13.) Same Tree 

The idea is to check whether two tree are one and the same

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {//here p is the root of the first tree and q is the root of the second tree
        if(p == NULL && q == NULL)// if both of the first node is NULL and equal then return true
           return true;
        else if(p == NULL || q == NULL)// if only either one of them is NULL, but the other node is not NULL, then return false
            return false;
        else
            return(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//else check the value by recursively travelling to the left and right thereby checking if the node values are equal, if they are equal then return true else return false
        
    }
};


