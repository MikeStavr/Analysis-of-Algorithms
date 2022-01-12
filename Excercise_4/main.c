#include <stdio.h>
#include <stdlib.h>

int N = 7; // change the size of the queue
int heap_size = 0; // do not change

struct client {
    int id;
    int priority;
};

int left(int i) {
    return i * 2;
}

int right(int i) {
    return i * 2 + 1;
}

int parent(int i) {
    return i / 2;
}

void min_heapify(struct client *heap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l <= heap_size && heap[l].priority < heap[i].priority) {
        smallest = l;
    }
    if (r <= heap_size && heap[r].priority < heap[smallest].priority) {
        smallest = r;
    }
    if (smallest != i) {
        struct client temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        min_heapify(heap, smallest);
    }
}

void removeMin(struct client *heap) {
    if (heap_size == 0) {
        printf("Heap is empty\n");
        return;
    }
    struct client min = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;
    min_heapify(heap, 1);
    printf("Removed client with id %d and priority %d\n", min.id, min.priority);
}

void removeSpecific(struct client *heap, int priority) {
    if (heap_size == 0) {
        printf("Heap is empty\n");
        return;
    }
    int i = 1;
    while (i <= heap_size && heap[i].priority != priority) {
        i++;
    }
    if (i > heap_size) {
        printf("No client with priority %d\n", priority);
        return;
    }
    struct client min = heap[i];
    heap[i] = heap[heap_size];
    heap_size--;
    min_heapify(heap, i);
    printf("Removed client with id %d and priority %d\n", min.id, min.priority);
}

void insertFirst(struct client *heap, int id) {
    int priority = 0;
    if (heap_size == N) {
        printf("\n*** Heap is full***\n");
        return;
    }
    heap_size++;
    int i = heap_size;
    while (i > 1 && priority < heap[parent(i)].priority) {
        heap[i] = heap[parent(i)];
        i = parent(i);
    }
    heap[i].id = id;
    heap[i].priority = priority;
}

void insertSpecific(struct client *heap, int id, int priority) {
    if (heap_size == N) {
        printf("Heap is full\n");
        return;
    }
    heap_size++;
    int i = heap_size;
    while (i > 1 && priority < heap[parent(i)].priority) {
        heap[i] = heap[parent(i)];
        i = parent(i);
    }
    heap[i].id = id;
    heap[i].priority = priority;
}

void printHeap(struct client *heap) {
	int i;
    printf("\n\n Printing heap \n \n");
    for (i = 1; i <= heap_size; i++) {
        printf("Client with id %d and priority %d\n\n", heap[i].id, heap[i].priority);
    }
}

int main() {
    int choice, id, priority;
    printf("1. Insert special client\n");
    printf("2. Insert client with given priority\n");
    printf("3. Delete client with given priority\n");
    printf("4. Remove client with highest priority\n");
    printf("5. Print queue\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    struct client queue[N];
    while (choice != 6) {
        switch (choice) {
            case 1:
                printf("Enter client id: ");
                scanf("%d", &id);
                insertFirst(queue, id);
                printHeap(queue);
                break;
            case 2:
                printf("Enter client id: ");
                scanf("%d", &id);
                printf("Enter client priority: ");
                scanf("%d", &priority);
                insertSpecific(queue, id, priority);
                printHeap(queue);
                break;
            case 3:
                printf("Enter priority to remove: ");
                scanf("%d", &priority);
                removeSpecific(queue, priority);
                printHeap(queue);
                break;
            case 4:
                removeMin(queue);
                printHeap(queue);
                break;
            case 5:
                printHeap(queue);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                break;
        }
        printf("1. Insert special client\n");
        printf("2. Insert client with given priority\n");
        printf("3. Delete client with given priority\n");
        printf("4. Remove client with highest priority\n");
        printf("5. Print queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("Final print of heap\n");
    printHeap(queue);
    return 0;
}

/**
 *
 * ✔ min_heapify() -> logic of making the min heapify
 *
 * ✔ removeMin() -> remove client with highest priority
 * ✔ removeSpecific(int id) -> remove `x` from heap and then rearrange the heap build_min_heap()
 *
 * ✔ insertFirst() -> insert a special client at the first position of the heap and then build_min_heap()
 * ✔ insertSpecific() -> insert a client at `x` position and then build_min_heap()
 *
 * ✔ displayQueue -> display the queue
 *
 * helping functions
 * left(i) -> find the left child of `i` = (i*2)
 * right(i) -> find the right child of `i` = (i*2+1)
 * parent(i) -> find the parent of `i` = i / 2
 */
