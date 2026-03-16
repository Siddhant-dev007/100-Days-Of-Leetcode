bool isPalindrome(struct ListNode* head) {
    int arr[100000];
    int i = 0;
    
    struct ListNode* temp = head;
    
    while(temp != NULL) {
        arr[i++] = temp->val;
        temp = temp->next;
    }
    
    int start = 0, end = i - 1;
    
    while(start < end) {
        if(arr[start] != arr[end])
            return false;
        start++;
        end--;
    }
    
    return true;
}
    
