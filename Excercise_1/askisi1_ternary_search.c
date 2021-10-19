// ? INFO: trenary search(triadiki anazitisi)

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define N 5000

int ternarySearch(int array[], int x, int left, int right) {
    int mid1;
    int mid2;
    int iters;

    while (left <= right) {
        iters++;
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        printf("\nmid1 = %d", mid1);
        printf("\nmid2 = %d", mid2);
       
        if (array[mid1] == x) {
            mid1 = x;
        }

        if (array[mid2] == x) {
            mid2 = x;
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
    printf("\nRequired %d iterations for number %d", iters, x);
    return iters;
}

int main() {
    int pin[N], i; // Define array of size N
    srand(time(NULL)); // start rand.
// 1+2+4+6+7+9+10+12+14+16

    pin[0] = rand() % 100; // set pin[0] a number from 0 to 99

    for (i = 1; i < N; i++)
        pin[i] = pin[i - 1] + rand() % 10; // fill the array in an ascending order.
        printf("\npin[%d] = %d",i, pin[i]);

    int sum;
    for (i = 0; i < 10; i++) {
        // ! Stops
        int toSearch = rand() % N; // Generate number between 0-N to use as a search case.
        int iteration = ternarySearch(pin, pin[toSearch], 0, N - 1);
        sum = sum + iteration;
    }
    int avg = sum / 10;
    printf("\nAverage %d comparisons for %d data.", avg, N);
}