#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000

int binarySearch(int array[], int x, int left, int right) {
  int mid;
  int iterations = 0;
  while (left <= right) {
    iterations += 1;
    mid = left + (right - left) / 2;
    if (array[mid] == x) {
      printf("\nFound %d after %d iterations", mid, iterations);
      return iterations;
    }
    if (array[mid] < x)
      left = mid + 1;
    else
      right = mid - 1;
  }
}

int main() {
  int pin[N], i, sum = 0;
  int random, bSearch;
  srand(time(NULL));
  pin[0] = rand() % 100;

  for (i = 1; i < N; i++)
    pin[i] = pin[i - 1] + rand() % 10;

  for (i = 0; i < 10; i++) {
    random = rand() % N;
    bSearch = binarySearch(pin, pin[random], 0, N - 1);

    if (bSearch == -1) {
      printf("\nNot found.");
    }

    sum = sum + bSearch;
  }
  printf("\nAverage iterations: %d", sum / 10);
}
