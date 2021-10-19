#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 5000

int binarySearch(int array[], int x, int left, int right){
	int mid;
	int iters = 0;
		while (left <= right){
  			  iters += 1;
			mid = left + (right - left) / 2;
			if(array[mid] == x){
				mid = x;
				break;
			}else if(array[mid] > x){
				left = mid + 1;
			}else {
				right = mid - 1;
			}
		}
		printf("\nRequired %d iterations for number %d", iters, x);
		return iters;
}

int main(){
	
	int pin[N], i;
     srand(time(NULL));
     pin[0] = rand()%100;
	for(i=1;i<N;i++)
		pin[i] = pin[i-1] + rand()%10;
	int sum;
	for(i = 0; i < 10; i++){
		  int toSearch = rand()%N; // thesi ths timhs
		  int iteration = binarySearch(pin, pin[toSearch], 0, N-1); // anazitisi sthn thesi aythn
		  sum = sum + iteration;
	}
	int mo = sum / 10;
	printf("\nAverage comparisons for %d data = %d.",N,mo);
}
