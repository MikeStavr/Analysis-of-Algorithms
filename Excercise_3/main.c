#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 12000
#define M 25000
#define K 50000

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void merge(int pin[], int left, int mid, int right) {
  int new = mid + 1;
  if (pin[mid] <= pin[new]) {
    return;
  }
  while (left <= mid && new <= right) {
    if (pin[left] <= pin[new]) {
      left++;
    } else {
      int value = pin[new];
      int index = new;
      while (index != left) {
        pin[index] = pin[index - 1];
        index--;
      }
      pin[left] = value;
      left++;
      mid++;
      new ++;
    }
  }
}

void mergeSort(int pin[], int left, int right) {
  int mid;
  if (left < right) {
    mid = (left + right) / 2;
    mergeSort(pin, left, mid);
    mergeSort(pin, mid + 1, right);
    merge(pin, left, mid, right);
  }
}

int partition(int pin[], int left, int right) {

  int pivot = pin[right];
  int store = (left - 1);
  int j;

  for (j = left; j < right; j++) {
    if (pin[j] <= pivot) {
      store++;
      swap(&pin[store], &pin[j]);
    }
  }

  swap(&pin[store + 1], &pin[right]);
  return (store + 1);
}

void quicksort(int pin[], int left, int right) {
  int pivot;
  if (left < right) {
    pivot = partition(pin, left, right);
    quicksort(pin, left, pivot - 1);
    quicksort(pin, pivot + 1, right);
  }
}
void generateRandomArray(int pin[], int number) {
  srand(time(NULL));
  int i;
  for (i = 0; i < number; i++) {
    int randomNumber = rand() % 50000;
    pin[i] = randomNumber;
  }
}
void emptyArray(int pin[], int number) {
  int i;
  for (i = 0; i < number; i++) {
    pin[i] = 0;
  }
}

int main() {
  int pin1[N], pin2[M], pin3[K];
  int i;
  double average1, average2, average3, average4, average5, average6;
  double time_taken;
  clock_t start;

  printf("\nBefore for < 10\n");
  for (i = 0; i < 10; i++) {
    generateRandomArray(pin1, N);
    generateRandomArray(pin2, M);
    generateRandomArray(pin3, K);

    printf("\nMerge sort 1\n");
    start = clock();
    mergeSort(pin1, 0, N - 1);
    start = clock() - start;
    time_taken = (double)(start) / CLOCKS_PER_SEC;
    average1 += time_taken;
    printf("\nMerge sort 2\n");
    start = clock();
    mergeSort(pin2, 0, M - 1);
    start = clock() - start;
    time_taken = (double)(start) / CLOCKS_PER_SEC;
    average2 += time_taken;
    printf("\nMerge sort 3\n");
    start = clock();
    mergeSort(pin3, 0, K - 1);
    start = clock() - start;
    time_taken = (double)(start) / CLOCKS_PER_SEC;
    average3 += time_taken;

    generateRandomArray(pin1, N);
    generateRandomArray(pin2, M);
    generateRandomArray(pin3, K);

    printf("\nQuick sort 1\n");
    start = clock();
    quicksort(pin1, 0, N - 1);
    start = clock() - start;
    time_taken = (double)(start) / CLOCKS_PER_SEC;
    average4 += time_taken;

    printf("\nQuick sort 2\n");
    start = clock();
    quicksort(pin2, 0, M - 1);
    start = clock() - start;
    time_taken = (double)(start) / CLOCKS_PER_SEC;
    average5 += time_taken;

    printf("\nQuick sort 3\n");
    start = clock();
    quicksort(pin3, 0, K - 1);
    start = clock() - start;
    time_taken = (double)(start) / CLOCKS_PER_SEC;
    average6 += time_taken;
  }

  printf("Merge sort:\n");
  printf("pin1 = %f", average1 / 10);
  printf("\npin2 = %f", average2 / 10);
  printf("\npin3 = %f", average3 / 10);

  printf("\nQuick sort:\n");

  printf("pin1 = %f", average4 / 10);
  printf("\npin2 = %f", average5 / 10);
  printf("\npin3 = %f", average6 / 10);
}