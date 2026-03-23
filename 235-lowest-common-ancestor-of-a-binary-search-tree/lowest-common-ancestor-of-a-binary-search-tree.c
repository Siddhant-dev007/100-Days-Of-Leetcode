struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;   // both in left
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;  // both in right
        } else {
            return root;         // split point = LCA
        }
    }
    return NULL;
}