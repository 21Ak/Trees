// Diameter : Longest Path between any 2 nodes, also this path does not need to pass via root

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
    int f(TreeNode* root, int& diameter){
        if(root==NULL)
            return 0;
        
        int lh = f(root->left, diameter);
        int rh = f(root->right, diameter);

        diameter=max(diameter, lh+rh);

        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        f(root, diameter);
        return diameter;
    }
};