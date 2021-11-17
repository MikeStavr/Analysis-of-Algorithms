#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 12000
#define M 25000
#define K 50000

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
  int pivot = right;
  int store = left - 1;
  int i;
  for (i = left; i < right; i++) {
    if (pin[i] <= pin[pivot]) {
      int temp = pin[i];
      pin[i] = pin[store];
      pin[store] = temp;
      store++;
    }
  }
  int temp2 = pin[pivot];
  pin[pivot] = pin[store];
  pin[store] = temp2;
  return store + 1;
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

int main() {
  int pin1[N], pin2[M], pin3[K];
  int i;
  double average1, average2, average3, average4, average5, average6;

  for (i = 0; i < 10; i++) {
    generateRandomArray(pin1, N);
    generateRandomArray(pin2, M);
    generateRandomArray(pin3, K);

    clock_t start1 = clock();
    mergeSort(pin1, 0, N - 1);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    average1 += time1;

    clock_t start2 = clock();
    mergeSort(pin2, 0, M - 1);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    average2 += time2;

    clock_t start3 = clock();
    mergeSort(pin3, 0, K - 1);
    clock_t end3 = clock();
    double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    average3 += time3;

    generateRandomArray(pin1, N);
    generateRandomArray(pin2, M);
    generateRandomArray(pin3, K);

    clock_t start4 = clock();
    quicksort(pin1, 0, N - 1);
    clock_t end4 = clock();
    double time4 = (double)(end4 - start4) / CLOCKS_PER_SEC;
    average4 += time4;

    clock_t start5 = clock();
    quicksort(pin2, 0, M - 1);
    clock_t end5 = clock();
    double time5 = (double)(end5 - start5) / CLOCKS_PER_SEC;
    average5 += time5;

    clock_t start6 = clock();
    quicksort(pin3, 0, K - 1);
    clock_t end6 = clock();
    double time6 = (double)(end6 - start6) / CLOCKS_PER_SEC;
    average6 += time6;
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