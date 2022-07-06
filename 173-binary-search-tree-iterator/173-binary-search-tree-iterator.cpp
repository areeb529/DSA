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
class BSTIterator {
public:
    TreeNode*ptr=new TreeNode(-1);
    stack<TreeNode*> st;
    void inorder(TreeNode*root){
        if(ptr||!st.empty()){
            TreeNode*cur=root;
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            ptr=st.top();
            st.pop();
        }
    }
    BSTIterator(TreeNode* root) {
        ptr->right=root;
    }
    
    int next() {
        if(ptr&&ptr->val==-1)ptr=ptr->right;
        inorder(ptr);
        int nextNode=ptr->val;
        ptr=ptr->right;
        return nextNode;
    }
    
    bool hasNext() {
        if(ptr&&ptr->val==-1&&ptr->right)return true;
        if(ptr||!st.empty())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */