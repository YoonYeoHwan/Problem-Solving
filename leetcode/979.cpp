// 979. Distribute Coins in Binary Tree

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
    int result;

    int distributeCoins(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
    
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int leftValue = dfs(root -> left);
        int rightValue = dfs(root -> right);
        result += abs(leftValue) + abs(rightValue);
        return root -> val + leftValue + rightValue - 1;
    }

};

