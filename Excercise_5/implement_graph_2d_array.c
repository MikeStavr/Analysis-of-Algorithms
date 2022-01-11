#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vertices 4

void setGraphMatrix(int mat[][vertices]) {
  int i, j;
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      mat[i][j] = 0;
    }
  }
}

void addEdge(int mat[][vertices], int i, int j) {
  mat[i][j] = 1;
  mat[j][i] = 1;
}

void print(int mat[][vertices]) {
  int i, j;
  for (i = 0; i < vertices; i++) {
    printf("\n");
    for (j = 0; j < vertices; j++) {
      printf("%d ", mat[i][j]);
    }
  }
}

int main() {
  int mat[vertices][vertices];

  setGraphMatrix(mat);
  addEdge(mat, 0, 1);
  addEdge(mat, 0, 2);
  addEdge(mat, 1, 2);
  addEdge(mat, 2, 0);
  addEdge(mat, 2, 3);
  addEdge(mat, 3, 3);

  print(mat);
}
