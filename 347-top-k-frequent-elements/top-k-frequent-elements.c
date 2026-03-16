typedef struct {
    int num;
    int freq;
} Node;

void swap(Node *a, Node *b){
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(Node heap[], int i){
    while(i > 0){
        int parent = (i - 1) / 2;
        if(heap[parent].freq <= heap[i].freq)
            break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(Node heap[], int size, int i){
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left].freq < heap[smallest].freq)
            smallest = left;
        if(right < size && heap[right].freq < heap[smallest].freq)
            smallest = right;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    int offset = 10000;
    int freq[20001] = {0};

    // Count frequency
    for(int i = 0; i < numsSize; i++)
        freq[nums[i] + offset]++;

    Node heap[k];
    int heapSize = 0;

    for(int i = 0; i < 20001; i++){
        if(freq[i] > 0){
            Node node;
            node.num = i - offset;
            node.freq = freq[i];

            if(heapSize < k){
                heap[heapSize] = node;
                heapifyUp(heap, heapSize);
                heapSize++;
            }
            else if(node.freq > heap[0].freq){
                heap[0] = node;
                heapifyDown(heap, heapSize, 0);
            }
        }
    }

    int *result = (int*)malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++)
        result[i] = heap[i].num;

    *returnSize = k;
    return result;
}