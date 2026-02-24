struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove matching nodes from beginning
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* curr = head;

    // Traverse and remove matching nodes
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}