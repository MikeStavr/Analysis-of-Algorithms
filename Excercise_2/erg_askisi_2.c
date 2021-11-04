#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define N 6000

int binary(int pin[], int left, int right, int x, int counter) {
  int mid;
  mid = left + (right - left) / 2;
  if (pin[mid] == x) {
    printf("\nFound %d after %d recursions", x, counter);
    return counter;
  }
  if (pin[mid] > x) {
    counter++;
    return binary(pin, left, mid - 1, x, counter);
  } else {
    counter++;
    return binary(pin, mid + 1, right, x, counter);
  }
  return -1;
}
int interpolation(int pin[], int left, int right, int x, int counter) {
  int mid;
  if (left <= right && x >= pin[left] && x <= pin[right]) {
    mid = left + (((double)(right - left) / (pin[right] - pin[left])) *
                  (x - pin[left]));
    if (pin[mid] == x) {
      printf("\nFound %d using interpolation search after %d recursions.", x,
             counter);
      return counter;
    }
    if (pin[mid] < x) {
      counter++;
      return interpolation(pin, mid + 1, right, x, counter);
    }
    if (pin[mid] > x) {
      counter++;
      return interpolation(pin, left, mid - 1, x, counter);
    }
  }
  return -1;
}

int main() {
  int pin1[N], pin2[N], pin3[N], i, summary1 = 0, summary2 = 0, summary3 = 0,
                                    summary4 = 0, summary5 = 0, summary6 = 0,
                                    counter = 0;
  srand(time(NULL));
  pin1[0] = rand() % 100;
  for (i = 1; i < N; i++)
    pin1[i] = pin1[i - 1] + (rand() % 10 + 1);

  pin2[0] = 0;
  for (i = 1; i < 2000; i++)
    pin2[i] = pin2[i - 1] + (rand() % 10 + 1);
  pin2[2000] = 10000;
  for (i = 2001; i < 4000; i++)
    pin2[i] = pin2[i - 1] + (rand() % 10 + 1);
  pin2[4000] = 30000;
  for (i = 4001; i < N; i++)
    pin2[i] = pin2[i - 1] + (rand() % 10 + 1);

  pin3[0] = rand() % 100;
  for (i = 1; i < N; i++)
    pin3[i] = pin3[i - 1] + (rand() % 1000 + 1);

  for (i = 0; i < 10; i++) {
    int r = rand() % N;

    printf("\n\nBinary");
    printf("\nPinakas 1:");
    int result1 = binary(pin1, 0, N - 1, pin1[r], counter);
    printf("\nPinakas 2:");
    int result2 = binary(pin2, 0, N - 1, pin2[r], counter);
    printf("\nPinakas 3:");
    int result3 = binary(pin3, 0, N - 1, pin3[r], counter);

    summary1 += result1;
    summary2 += result2;
    summary3 += result3;

    printf("\n\nInterpolation");
    printf("\nPinakas 1");
    int result4 = interpolation(pin1, 0, N - 1, pin1[r], counter);
    printf("\nPinakas 2");
    int result5 = interpolation(pin2, 0, N - 1, pin2[r], counter);
    printf("\nPinakas 3");
    int result6 = interpolation(pin3, 0, N - 1, pin3[r], counter);

    summary4 += result4;
    summary5 += result5;
    summary6 += result6;
  }
  printf("\n\nBinary:");
  printf("\nPinakas 1: %d", summary1 / 10);
  printf("\nPinakas 2: %d", summary2 / 10);
  printf("\nPinakas 3: %d", summary3 / 10);
  printf("\n\nInterpolation:");
  printf("\nPinakas 1: %d", summary4 / 10);
  printf("\nPinakas 2: %d", summary5 / 10);
  printf("\nPinakas 3: %d", summary6 / 10);
}