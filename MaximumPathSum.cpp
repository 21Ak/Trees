// If we are at a node, and calculate maxSumPathLeft(maxL) and maxSumPathRight(maxR), then maxSumPath = node->val + (maxL+maxR)
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
    int maxPath(TreeNode* node, int &maxi){
        if(node == NULL)
            return 0;
        
        // if any side sum is negative, take 0, instead of negative sum
        int leftSum = max(0,maxPath(node->left, maxi));
        int rightSum = max(0,maxPath(node->right, maxi));

        maxi = max(maxi, leftSum + rightSum + node->val);

        return node->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};