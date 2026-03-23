struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Step 1: If tree is empty, create new node
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Step 2: Traverse left or right
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    // Step 3: Return unchanged root
    return root;
}