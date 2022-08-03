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
            
            if(mpp.find(line) == mpp.end())//if that node is not in the map, then add it into the map, whenever the first node in the line is visited, then it is put into the map and that gives us the ans
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
            return(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//else check the value by recursively travelling to the left and right thereby 
            //checking if the node values are equal, if they are equal then return true else return false
        
    }
};



14.) Bottom View of a Binary Tree

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14
    
    -->Here the bottom view is 5, 10, 3, 14, 25
    -->Draw parallel vertical lines, the bottom view is the last element present in the vertical elements (also known as the vertical order traversal)
    -->From a particular node, if we travel left then [level=level-1], if we travel right the [level=level+1], and root node will be level 0 
    -->Here, we are to going to maintain a queue and a map data structure, 
    -->Queue DS stores (node,line) of all nodes available by travelling left and right , once a node's left and right are visited then the pair(line,pair) is added into the map DS
    -->Map DS stores (line, node) and only one pair per vertical line
    -->Map stores every thing in ascending order, -2, -1, 0, 1, 2 it stores in this way
    -->Then Traverse the map, where the node is pushed into the vector iteratively each time, where we get the bottom view of Binary Tree stored in the vector
    
    
    
    
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;//vector which stores the bottom view of the binary tree
        if(root == NULL)//if the tree is empty, return null
            return ans;
            
        queue<pair<Node*, int>> q; // queue data structure which stores (node,line)
        map<int, int> mpp;//stores the (line, node), but only one pair per line
        
        q.push({root, 0});// we push (root,0) i.e we push node and the line at which that 
        //node is present
        while(!q.empty())//we traverse until the queue is empty
        {
            auto it = q.front();//iterator it will always point to the front node of the queue
            q.pop();//that node which is put into the queue is poped
            
            Node* node = it.first;//node is first part of the queue
            int line = it.second;// the line in which the node is present is the second part of the queue
            mpp[line] = node->data;// here each time from the queue, we are storing into the map, the data of the node with the line
            
            
            //the diff b/w top view and bottom view is that in top view only the first occurence of a node in line is pushed into the map
            //but in bottom it is done until the last level by travelling downwards until the last level and get updated each time
            
            
            if(node->left != NULL)//we check the node->left is null, if not 
            //null then push that pair into the queue
                q.push({node->left, line-1});//we push that node->left and making the line-1
            
            if(node->right != NULL)//we check the node->right is null, if not 
            //null then push that pair into the queue
                q.push({node->right, line+1});//we push that node->right and making the line+1
            
        }
        
        for(auto it: mpp)
                ans.push_back(it.second);// iteratively, we are pushing the only the node into the map
                
        return ans;
    }
    
};



15.) Post Oder traversal of a binary tree

--> can be solved by using 2 stack and one stack method
-->post order----Left, right, root

Using 2 stack method:


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;//this vector stores the postorder traversal of the binary tree
        if(root == NULL)//if the tree is empty then return empty vector
            return postorder;
        
        stack<TreeNode*> st1, st2;//creating two stacks st1, st2
        //the first stack st1 stores the visited nodes
        //the second stack st2 stores the postorder traversal of the binary tree
        st1.push(root);//first push the root in the stack
        
        while(!st1.empty())
        {
            root = st1.top();// make root the topmost element of the stack
            st1.pop();//and pop it from the stack
            st2.push(root);// push that value into the second stack st2
            
            if(root->left != NULL)//if root of left is not null, then push it into the stack
                st1.push(root->left);
            
            if(root->right != NULL)//if root of right is not null, then push it into the stack
                st1.push(root->right);
            
        }
        
        while(!st2.empty())
        {
            postorder.push_back(st2.top()->val);//putting the values of st2 from top to bottom in the postorder vector
            st2.pop();//once a node is pushed into the vector, that element is poped from the stack
        }
        
        return postorder;
    }
};


16.) Root to node path in a binary tree

bool getpath(TreeNode* root, vector<int> &arr, int x)//root is the place where we are goint to start, arr stores the root to node path A
 //and x is the node to which the path has to be found
 {
     if(root == NULL)//if root is NULL, then return false
        return false;
     arr.push_back(root->val);//always add that node into the arr vector
     
     if(root->val == x)//check if the value matches, if it does return true
        return true;
        
     else if(getpath(root->left, arr, x) || getpath(root->right, arr, x))//if either left or right node value matches then return true with the path arr(vector)
        return true;
        
    else{
        arr.pop_back();// if value not found in either left and right, then remove the last element from the vector
        return false;// if not found then return false
    }
    
        
    
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr; // to store the path from the root to the a given node
    if(A == NULL)
        return arr;
    getpath(A, arr, B);
    
    return arr;
    
    
}


This is a typical DFS traversal and TC=0(n) and SC=0(H) where H is the height of the tree


17.) Lowest common ancestor of a binary tree

              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
    
-->given two nodes, we need to find the path of root to individual 
-->we will have two arrays or vector to store the path
--> for node n1=7, path = [5, 6, 7]
             n2=8, path = [5, 6, 7, 8]
-->we keep on check whether both path vector are same
-->at one point the two vectors wont be the same, return the previous node where the equality went false
-->here in this case, at 8 the equality went false, so return the previous node as the answer

--> here also we use the DFS traversal(preorder traversal)
--> here the TC = SC = 0(N)
    
    
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)//if we root is NULL, the nodes p and q given, then we return the node itself
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);//move to left
        TreeNode* right = lowestCommonAncestor(root->right, p, q);// move to right
        
        if(left == NULL)//if one of the node is NULL , return the other
            return right;
        else if (right == NULL)//if one of the node is NULL , return the other
            return left;
        else//this case give us the ans
            return root;// if both left and right are not NULL, then we the return the node itself
    }
};




18.) Maximum width of a binary tree

--> Max Width is no of nodes in a level b/w any 2 nodes
--> Level order traversal is used to find the max width
--> If we index the nodes, it will be easier to find the width
--> In any level, max width = last index - first index + 1
--> For indexing, 
        if the index of a node is i, then left index = (2*i) + 1        this is for 0 based indexing
                                         right index = (2*i) + 2


