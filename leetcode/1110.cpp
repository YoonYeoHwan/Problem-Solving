// 1110. Delete Nodes And Return Forest

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> result;
    set<int> s;
    
    TreeNode* dfs(TreeNode* root, set<int>& to_delete) {
        
        if(root == NULL) return NULL;
        root -> left = dfs(root -> left, to_delete);
        root -> right = dfs(root -> right, to_delete);
        
        if(s.find(root -> val) != s.end()) {
            if(root -> left != NULL) result.push_back(root -> left);
            if(root -> right != NULL) result.push_back(root -> right);
            root = NULL;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(int i : to_delete) s.insert(i);
        
        root = dfs(root, s);
        if(root != NULL) result.push_back(root);
        
        return result;
    }
};

