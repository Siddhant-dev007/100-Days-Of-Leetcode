int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize - 1];
            numsSize--;   // shrink array size
        }
         else
          {
            i++;
          }
    }
    return numsSize;
 
}