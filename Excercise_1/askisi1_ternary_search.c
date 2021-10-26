#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000

int ternarySearch(int array[], int x, int left, int right) {
  int mid1;
  int mid2;

  int iters = 0;

  while (left <= right) {
    iters += 1;
    mid1 = left + (right - left) / 3;
    mid2 = right - (right - left) / 3;

    if (array[mid1] == x) {
      x = mid1;
      break;
    }

    if (array[mid2] == x) {
      x = mid2;
      break;
    }
    if (array[mid1] > x) {

      right = mid1 - 1;

    } else if (array[mid2] < x) {

      left = mid2 + 1;

    } else {
      left = mid1 + 1;
      right = mid2 - 1;
    }
  }
  printf("\nRequired %d iterations for number at slot %d", iters, x);
  return iters;
}

int main() {

  int pin[N], i, avg = 0, sum = 0;

  srand(time(NULL));
  pin[0] = rand() % 100;

  for (i = 1; i < N; i++)
    pin[i] = pin[i - 1] + rand() % 10;

  for (i = 0; i < 10; i++) {
    int toSearch = rand() % N;
    int iteration = ternarySearch(pin, pin[toSearch], 0, N - 1);
    sum = sum + iteration;
  }
  avg = sum / 10;
  printf("\nAverage %d comparisons for %d data.", avg, N);
}