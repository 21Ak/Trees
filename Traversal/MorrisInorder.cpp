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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;

        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                {
                    // going to rightmost node
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    // create thread that points to the root ie cur and then moving to left node
                    prev->right = cur;
                    // inorder.push_back(cur->val); // for preorder morris traversal
                    cur = cur->left;
                }
                else
                {
                    // there exist a thread already, cutting the thread, and then moving to right
                    prev->right = NULL;
                    inorder.push_back(cur->val); // for inorder morris traversal
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};