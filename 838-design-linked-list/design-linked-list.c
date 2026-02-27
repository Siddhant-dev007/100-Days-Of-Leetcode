#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;


/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}


/** Get the value of the index-th node in the linked list. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}


/** Add at head */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}


/** Add at tail */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* temp = obj->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    obj->size++;
}


/** Add at index */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;

    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    obj->size++;
}


/** Delete at index */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp = obj->head;

    if (index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }

    obj->size--;
}


/** Free entire list */
void myLinkedListFree(MyLinkedList* obj) {
    Node* current = obj->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}