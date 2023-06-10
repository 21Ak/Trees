// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
private:
    bool f(TreeNode* lnode, TreeNode* rnode){
        if(lnode==NULL || rnode==NULL)
            return lnode==rnode;
        
        if(lnode->val!=rnode->val)
            return false;

        return f(lnode->left, rnode->right) && f(lnode->right, rnode->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return f(root->left, root->right);
    }
};