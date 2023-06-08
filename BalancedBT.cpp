// Balanced Binary Tree: For every node |height(left subtree) - height(right subtree)| <= 1
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
private :
    int check(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int lh = check(root->left);
        if(lh == -1) return -1;

        int rh = check(root->right);
        if(rh == -1) return -1;

        // If at any moment diff in height becomes >1, we will return -1 otherwise it will return the height of the tree
        if(abs((lh-rh)) > 1) return -1;

        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(check(root) == -1) return false;
        else return true;
    }
};