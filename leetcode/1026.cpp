// 1026. Maximun difference Between Node and Ancestor

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
    int MAX;
    int MIN;
    int result = 0;
    int maxAncestorDiff(TreeNode* root) {
        MAX = root -> val;
        MIN = root -> val;
        dfs(root);
        return result;
    }
    
    TreeNode* dfs(TreeNode* root) {
        if(root == NULL) return NULL;
        
        int curr = root -> val;
        int MAX_TMP = MAX;
        int min_tmp = MIN;
        
        MAX = max(curr, MAX);
        MIN = min(curr, MIN);
        result = max(result, abs(MAX - MIN));
        
        root -> left = dfs(root -> left);
        
        if(MIN < curr) MIN = min_tmp;
        if(MAX > curr) MAX = MAX_TMP;
        
        root -> right = dfs(root -> right);
        
        return root;
    }
};

