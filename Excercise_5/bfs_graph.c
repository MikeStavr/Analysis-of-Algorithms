#include <stdio.h>
#include <stdlib.h>

#define N 50

struct node {
  int v;
  struct node* next;
};

struct queue {
  int queue[N];
  int first;
  int last;
};

struct Graph {
  int vertices;
  struct node** array;
  int* visited;
};

void print(struct queue*);
struct node* addNode(int);
struct Graph* generateGraph(int);
void search(struct Graph*, int);
void addNewEdge(struct Graph*, int, int);
struct queue* generateQueue();
void addToQueue(struct queue*, int);
int removeFromQueue(struct queue*);
int isEmpty(struct queue*);
void search(struct Graph*, int);

void print(struct queue* queue) {
  int index = queue->first;
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
  } else {
    printf("The queue has:\n");
    for (index = queue->first; index < queue->last + 1; index++) {
      printf("%d ", queue->queue[index]);
    }
  }
}

struct node* addNode(int v) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->v = v;
  node->next = NULL;
  return node;
}

struct Graph* generateGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;
  graph->array = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->array[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void search(struct Graph* graph, int begin) {
  struct queue* queue = generateQueue();

  graph->visited[begin] = 1;
  addToQueue(queue, begin);

  while (!isEmpty(queue)) {
    print(queue);
    int current = removeFromQueue(queue);
    printf("\nVisited vertex %d\n", current);

    struct node* helper = graph->array[current];
    while (helper) {
      int currentVertex = helper->v;

      if (graph->visited[currentVertex] == 0) {
        graph->visited[currentVertex] = 1;
        addToQueue(queue, currentVertex);
      }
      helper = helper->next;
    }
  }
}

void addNewEdge(struct Graph* graph, int e1, int e2) {
  // create link between e2 and e1
  struct node* newNode = addNode(e2);
  newNode->next = graph->array[e1];
  graph->array[e1] = newNode;

  // create link between e1 and e2

  newNode = addNode(e1);
  newNode->next = graph->array[e2];
  graph->array[e2] = newNode;
}

struct queue* generateQueue() {
  struct queue* queue = malloc(sizeof(struct queue));
  queue->first = -1;
  queue->last = -1;
  return queue;
}
int isEmpty(struct queue* queue) {
  if (queue->last == -1) {
    return 1;
  } else {
    return 0;
  }
}
void addToQueue(struct queue* queue, int item) {
  if (queue->last == N - 1) {
    printf("The queue is full.\n");
  } else {
    if (queue->first == -1) {
      queue->first = 0;
    }
    queue->last++;
    queue->queue[queue->last] = item;
  }
}
int removeFromQueue(struct queue* queue) {
  int removed;
  if (isEmpty(queue)) {
    printf("The queue is empty.\n");
    removed = -1;
  } else {
    removed = queue->queue[queue->first];
    queue->first++;
    if (queue->first > queue->last) {
      printf("The queue is empty, resetting\n");
      queue->first = queue->last = -1;
    }
  }
  return removed;
}

int main() {
  int vertices, i, e1, e2;
  printf("How many vertices in this graph? ");
  scanf("%d", &vertices);
  struct Graph* graph = generateGraph(vertices);

  for (i = 0; i < vertices; i++) {
    printf("Vertex %d\n", i);
    printf("Edges:");
    scanf("%d %d", &e1, &e2);
    addNewEdge(graph, e1, e2);
  }
  printf("Breadth first search on the graph:\n");
  search(graph, 0);
  return 0;
}
