#include <stdlib.h>

void inorder(struct TreeNode* root, int* result, int* index)
{
    if(root == NULL)
        return;

    inorder(root->left, result, index);

    result[*index] = root->val;
    (*index)++;

    inorder(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *result = malloc(sizeof(int) * 100);
    int index = 0;

    inorder(root, result, &index);

    *returnSize = index;
    return result;
}