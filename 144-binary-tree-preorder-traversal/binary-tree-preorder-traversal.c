void preorder(struct TreeNode* root, int* result, int* index)
{
    if(root == NULL)
        return;

    result[*index] = root->val;
    (*index)++;

    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *result = malloc(sizeof(int) * 100);
    int index = 0;

    preorder(root, result, &index);

    *returnSize = index;
    return result;
}