/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    // Base case
    if (root == NULL) {
        return 0;
    }

    // Recursive calls
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return max + 1 (for current node)
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}