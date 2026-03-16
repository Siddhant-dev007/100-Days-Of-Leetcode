typedef struct {
    int inStack[100];
    int outStack[100];
    int inTop;
    int outTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->inTop = -1;
    obj->outTop = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++obj->inTop] = x;
}

void moveStacks(MyQueue* obj) {
    if(obj->outTop == -1) {
        while(obj->inTop != -1) {
            obj->outStack[++obj->outTop] = obj->inStack[obj->inTop--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    moveStacks(obj);
    return obj->outStack[obj->outTop--];
}

int myQueuePeek(MyQueue* obj) {
    moveStacks(obj);
    return obj->outStack[obj->outTop];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->inTop == -1 && obj->outTop == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}