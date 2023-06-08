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

// Apply any traversal technique and at each node check if it is same or not
class Solution {
private:
    bool isSame(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL)
            return (p==q);
        
        if(p->val==q->val && isSame(p->left,q->left) && isSame(p->right, q->right)) return true;
        else return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};