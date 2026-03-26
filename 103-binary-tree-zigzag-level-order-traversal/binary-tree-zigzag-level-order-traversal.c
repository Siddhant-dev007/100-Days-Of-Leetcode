// Queue implementation
struct TreeNode* queue[2000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Main function
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    enqueue(root);
    int leftToRight = 1;
    int level = 0;

    while (!isEmpty()) {
        int size = rear - front;

        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();

            int index = leftToRight ? i : (size - 1 - i);
            result[level][index] = node->val;

            if (node->left) enqueue(node->left);
            if (node->right) enqueue(node->right);
        }

        leftToRight = !leftToRight;
        level++;
    }

    *returnSize = level;
    return result;
}