// 1123. Lowest Common Ancestor of Deepest Leaves

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(!root) return NULL;
        int l = depth(root -> left);
        int r = depth(root -> right);
        
        if(l == r) return root;
        else if (l > r) return lcaDeepestLeaves(root -> left);
        else return lcaDeepestLeaves(root -> right);
    }
    
    int depth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(depth(root -> left), depth(root -> right));
    }
};

