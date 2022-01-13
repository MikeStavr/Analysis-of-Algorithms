#include <stdio.h>
#include <stdlib.h>

struct node {
  int v;
  struct node *next;
};

struct Graph {
  int vertices;
  struct node **array;
  int *visited;
};

void search(struct Graph *, int);
struct node *addNode(int);
struct Graph *generateGraph(int);
void addNewEdge(struct Graph *, int, int);
void print(struct Graph *);

void search(struct Graph *graph, int v) {
  struct node *array = graph->array[v];
  struct node *helper = array;

  graph->visited[v] = 1;
  printf("Latest visited is %d\n", v);

  while (helper != NULL) {
    int vertex = helper->v;
    if (graph->visited[vertex] == 0) {
      search(graph, vertex);
    }
    helper = helper->next;
  }
}

struct node *addNode(int v) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->v = v;
  node->next = NULL;
  return node;
}

struct Graph *generateGraph(int vertices) {
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;
  graph->array = malloc(vertices * sizeof(struct node *));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->array[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addNewEdge(struct Graph *graph, int e1, int e2) {
  // create link between e2 and e1
  struct node *newNode = addNode(e2);
  newNode->next = graph->array[e1];
  graph->array[e1] = newNode;

  // create link between e1 and e2

  newNode = addNode(e1);
  newNode->next = graph->array[e2];
  graph->array[e2] = newNode;
}

void print(struct Graph *graph) {
  int i;
  for (i = 0; i < graph->vertices; i++) {
    struct node *helper = graph->array[i];
    printf("The graph:\n");
    while (helper != NULL) {
      printf("-> %d", helper->v);
      helper = helper->next;
    }
    printf("\n");
  }
}

int main() {
  int vertices, i, e1, e2, vertex;

  printf("How many vertices in this graph? ");
  scanf("%d", &vertices);

  struct Graph *graph = generateGraph(vertices);

  for (i = 0; i < vertices; i++) {
    printf("Vertex %d\n", i);
    printf("Edges: ");
    scanf("%d %d", &e1, &e2);
    addNewEdge(graph, e1, e2);
  }

  print(graph);

  printf("Which vertex do you want to set as the beginning? ");
  scanf("%d", &vertex);

  search(graph, vertex);
}