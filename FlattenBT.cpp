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

// Flatten the given binary tree into a linked list by rearranging the nodes of the given binary tree


class Solution {
public:
    // TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        // // Recursive Solution
        // // moving to the right and then left
        // flatten(root->right);
        // flatten(root->left);

        // // attaching left prev node to the current node's left and making left node null
        // // following left right root
        // root->right = prev;
        // root->left = NULL;
        // prev = root;

        // // Iterative soln
        // stack<TreeTreeNode*> st;
        // st.push(root);

        // while(!st.empty()){
        //     TreeTreeNode* cur = st.top();
        //     st.pop();

        //     if(cur->right!=NULL){
        //         st.push(cur->right);
        //     }
        //     if(cur->left!=NULL){
        //         st.push(cur->left);
        //     }

        //     if(!st.empty()){
        //         cur->right = st.top();
        //         cur->left = NULL;
        //     }
        // }

        // Using Morris traversal concept TC O(N), SC O(1)
        TreeNode* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
};