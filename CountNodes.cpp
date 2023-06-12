// Count nodes in complete binary tree in less than O(n) time complexity
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
    int findHeightLeft(TreeNode* node){
        int h = 0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }
    int findHeightRight(TreeNode* node){
        int h = 0;
        while(node){
            h++;
            node = node->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh) return (1<<lh)-1; // 2^lh - 1

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};