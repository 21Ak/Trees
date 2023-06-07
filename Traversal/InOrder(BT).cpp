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
    void inOrder(TreeNode* node, vector<int> &ans){
        if(node == NULL) return;

        inOrder(node->left, ans);
        ans.push_back(node->val);
        inOrder(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // // Recursive
        // vector<int> ans;
        // inOrder(root, ans);
        // return ans;

        // Iterative
        vector<int> ans;
        if(root == NULL) return ans;

        stack<TreeNode*> st;

        while(true){
            if(root!=NULL){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty() == true) break;

                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};