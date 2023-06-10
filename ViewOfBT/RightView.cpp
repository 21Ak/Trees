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
    void f(TreeNode* node, int level, vector<int>& ans){
        if(node==NULL)
            return;
        
        if(level == ans.size()){
            // if it is the first rightmost node on the level
            ans.push_back(node->val);
        }
        f(node->right, level+1, ans);
        f(node->left, level+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // we will do reverse preorder traversal
        // root right left

        vector<int> ans;
        if(root==NULL)
            return ans;
        
        f(root, 0, ans);
        return ans;
    }
};