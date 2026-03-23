struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case
    if (root == NULL || root->val == val) {
        return root;
    }

    // Use BST property
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}