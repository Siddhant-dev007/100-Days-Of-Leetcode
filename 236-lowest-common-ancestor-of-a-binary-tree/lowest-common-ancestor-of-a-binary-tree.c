struct TreeNode* lowestCommonAncestor(struct TreeNode* root, 
                                      struct TreeNode* p, 
                                      struct TreeNode* q) {
    if (root == NULL)
        return NULL;

    // If current node is p or q
    if (root == p || root == q)
        return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-null → this is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-null side
    return (left != NULL) ? left : right;
}