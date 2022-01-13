#include <stdio.h>
#include <stdlib.h>

#define N 5

struct node {
  int v;
  struct node* next;
};

struct AdjGraph {
  int vertices;
  struct node** array;
};

struct node* addNode(int v) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->v = v;
  node->next = NULL;
  return node;
}

struct AdjGraph* generateGraph(int vertices) {
  struct AdjGraph* graph = (struct AdjGraph*)malloc(sizeof(struct AdjGraph));
  graph->vertices = vertices;
  graph->array = malloc(vertices * sizeof(struct node*));

  for (int i = 0; i < vertices; i++) {
    graph->array[i] = NULL;
  }
  return graph;
}

/**
 * @brief create new edge for the graph
 *
 * @param graph - A graph for the edges to be added
 * @param e1 - The source edge
 * @param e2 - The destination edge
 */

void addNewEdge(struct AdjGraph* graph, int e1, int e2) {
  // create link between e2 and e1
  struct node* newNode = addNode(e2);
  newNode->next = graph->array[e1];
  graph->array[e1] = newNode;

  // create link between e1 and e2

  newNode = addNode(e1);
  newNode->next = graph->array[e2];
  graph->array[e2] = newNode;
}

void print(struct AdjGraph* graph) {
  for (int i = 0; i < graph->vertices; i++) {
    struct node* helper = graph->array[i];
    printf("\n%d\n", i);
    while (helper != NULL) {
      printf("%d-> ", helper->v);
      helper = helper->next;
    }
    printf("\n");
  }
}

int main() {
  int vertices, e1, e2, i;
  printf("How many vertices in this graph? ");
  scanf("%d", &vertices);
  struct AdjGraph* newGraph = generateGraph(vertices);

  for (i = 0; i < vertices; i++) {
    printf("Enter values for vertex %d: \n", i);
    printf("Separate edges with a space, for example: 0 2\n");
    printf("Edges: ");
    scanf("%d %d", &e1, &e2);
    fflush(stdin);
    addNewEdge(newGraph, e1, e2);
  }
  printf("\n\nFinal graph \n\n");
  print(newGraph);
}
