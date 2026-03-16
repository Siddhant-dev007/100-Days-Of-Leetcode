typedef struct {
    int maxHeap[50000];
    int minHeap[50000];
    int maxSize;
    int minSize;
} MedianFinder;

/* ---------- Utility ---------- */

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- Max Heap ---------- */

void maxHeapUp(MedianFinder *obj, int i){
    while(i > 0){
        int parent = (i-1)/2;
        if(obj->maxHeap[parent] >= obj->maxHeap[i]) break;
        swap(&obj->maxHeap[parent], &obj->maxHeap[i]);
        i = parent;
    }
}

void maxHeapDown(MedianFinder *obj, int i){
    while(1){
        int left = 2*i+1, right = 2*i+2, largest = i;

        if(left < obj->maxSize && obj->maxHeap[left] > obj->maxHeap[largest])
            largest = left;
        if(right < obj->maxSize && obj->maxHeap[right] > obj->maxHeap[largest])
            largest = right;

        if(largest == i) break;

        swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
        i = largest;
    }
}

void maxPush(MedianFinder *obj, int val){
    obj->maxHeap[obj->maxSize] = val;
    maxHeapUp(obj, obj->maxSize);
    obj->maxSize++;
}

int maxPop(MedianFinder *obj){
    int root = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[obj->maxSize-1];
    obj->maxSize--;
    maxHeapDown(obj,0);
    return root;
}

/* ---------- Min Heap ---------- */

void minHeapUp(MedianFinder *obj, int i){
    while(i > 0){
        int parent = (i-1)/2;
        if(obj->minHeap[parent] <= obj->minHeap[i]) break;
        swap(&obj->minHeap[parent], &obj->minHeap[i]);
        i = parent;
    }
}

void minHeapDown(MedianFinder *obj, int i){
    while(1){
        int left = 2*i+1, right = 2*i+2, smallest = i;

        if(left < obj->minSize && obj->minHeap[left] < obj->minHeap[smallest])
            smallest = left;
        if(right < obj->minSize && obj->minHeap[right] < obj->minHeap[smallest])
            smallest = right;

        if(smallest == i) break;

        swap(&obj->minHeap[i], &obj->minHeap[smallest]);
        i = smallest;
    }
}

void minPush(MedianFinder *obj, int val){
    obj->minHeap[obj->minSize] = val;
    minHeapUp(obj, obj->minSize);
    obj->minSize++;
}

int minPop(MedianFinder *obj){
    int root = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[obj->minSize-1];
    obj->minSize--;
    minHeapDown(obj,0);
    return root;
}

/* ---------- Median Finder ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder *obj = malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if(obj->maxSize == 0 || num <= obj->maxHeap[0])
        maxPush(obj, num);
    else
        minPush(obj, num);

    /* Balance heaps */
    if(obj->maxSize > obj->minSize + 1)
        minPush(obj, maxPop(obj));
    else if(obj->minSize > obj->maxSize)
        maxPush(obj, minPop(obj));
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}