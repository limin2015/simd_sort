#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define NUM 1000
void init(int *arr, int length){
	int i;
	srand(time(NULL));
	for(i = 0; i < length; i++){
		arr[i] = rand()%NUM + 1;
	}
}
void print(int *arr, int length){
	int i;
	for(i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");

}
void dtime(){
}
int main(){
	int arr[9]={2,9,6,5,0,3,7,1,8};
	int brr[18]={2,9,6,5,0,3,7,1,8,13,19,11,10,12,11,16,15,18};
	int i;
	int crr[NUM];
	init(crr, NUM);
	
//	combsort(arr, 9);
//	combsort(brr, 18);
	//combsort(crr, NUM);
	//print(crr, NUM);
	simd_in_core_sort(arr, NUM);


	return 0;
}
