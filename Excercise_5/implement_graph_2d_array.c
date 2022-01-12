#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillGraph(int **mat, int v1, int v2) {
  int i, j;
  for (i = 0; i < v1; i++) {
    for (j = 0; j < v2; j++) {
      mat[i][j] = 0;
    }
  }
}
void addEdge(int **mat, int m, int n) {
  mat[m][n] = 1;
  mat[n][m] = 1;
}

int main() {
  int v;
  printf("Input how many vertices there will be: ");
  scanf("%d", &v);
  int **mat = (int **)malloc(v * sizeof(int *));
  int i, j;
  for (i = 0; i < v; i++) {
    mat[i] = (int *)malloc(v * sizeof(int));
  }

  fillGraph(mat, v, v);
  addEdge(mat, 0, 1);
  addEdge(mat, 0, 2);
  addEdge(mat, 1, 2);
  addEdge(mat, 2, 0);
  addEdge(mat, 2, 3);
  addEdge(mat, 3, 3);

  // Printing the array
  for (i = 0; i < v; i++) {
    for (j = 0; j < v; j++) {
      printf("%3d ", mat[i][j]);
    }
    printf("\n");
  }
  // Freeing the space of the array
  for (i = 0; i < v; i++) {
    free(mat[i]);
  }
  // Free the array out of the memory
  free(mat);
  return 0;
}