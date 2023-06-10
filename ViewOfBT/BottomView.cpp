// Bottom View
// If overlapping nodes, then take the right node
// we do level order traversal and using the line concept of vertical order, replace if another node is found at same level
// this will give the endmost nodes in each line, hence we get bottom view of the tree

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 

        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; // replacing node in the same line
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};