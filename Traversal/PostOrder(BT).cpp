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
    void postOrder(TreeNode* node, vector<int>& ans){
        if(node == NULL) return;

        postOrder(node->left, ans);
        postOrder(node->right, ans);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // // Recursive
        // vector<int> ans;
        // postOrder(root, ans);
        // return ans;

        // Iterative
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st1;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            ans.push_back(root->val);
            if(root->left!=NULL)
                st1.push(root->left);
            if(root->right!=NULL)
                st1.push(root->right);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};