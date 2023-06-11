// Width : number of nodes in a level between any 2 nodes
// max Width : maximum number of nodes in a level between any 2 nodes
// Using level order traversal, we will index nodes of the tree
// then at every level max width = lastIndex-firstIndex+1

// for 0 based indexing 
// left node will be indexed : (2*i+1)
// right node wil be indexed : (2*i+2)

// since every time multiplying by 2 will give integer overflow, every time moving on to the next we will assign indexes from 0 again

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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second; // to make the index start from 0
            int first, last;
            for(int i=0; i<size; i++){
                long long int cur_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;

                if(node->left)
                    q.push({node->left, cur_id*2+1});
                if(node->right)
                    q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};