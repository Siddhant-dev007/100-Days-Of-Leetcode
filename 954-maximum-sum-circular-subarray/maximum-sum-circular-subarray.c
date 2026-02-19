int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    
    int max_sum = nums[0];
    int curr_max = 0;
    
    int min_sum = nums[0];
    int curr_min = 0;
    
    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];
        
        // Kadane for max
        curr_max = (curr_max > 0) ? curr_max + num : num;
        if(curr_max > max_sum)
            max_sum = curr_max;
        
        // Kadane for min
        curr_min = (curr_min < 0) ? curr_min + num : num;
        if(curr_min < min_sum)
            min_sum = curr_min;
        
        total += num;
    }
    
    // If all numbers are negative
    if(max_sum < 0)
        return max_sum;
    
    // Circular case
    int circular_max = total - min_sum;
    
    return (max_sum > circular_max) ? max_sum : circular_max;
}
