int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *deque = (int*)malloc(sizeof(int) * numsSize);
    
    int front = 0, rear = -1;
    int idx = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        // Remove indices out of window
        if(front <= rear && deque[front] <= i - k)
            front++;
        
        // Remove smaller elements from back
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;
        
        // Insert current index
        deque[++rear] = i;
        
        // Record max when window is ready
        if(i >= k - 1)
            result[idx++] = nums[deque[front]];
    }
    
    *returnSize = idx;
    
    free(deque);
    return result;
}