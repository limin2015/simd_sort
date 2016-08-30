/*
 improved bubble sort
not simd:infered one.
 */
#include "sort.h"
void combsort(TYPE *arr, int length){
	int gap = length/SHRINK_FACTOR;
	int i;

	while(gap > 1){
		for(i = 0; i < length-gap; i++){
			if(arr[i]>arr[i+gap])
				swap(&arr[i], &arr[i+gap]);
		gap = gap/SHRINK_FACTOR;
		}
	}

	//if flag ==0,then sort is not completed.
	int flag = 0;
	while(!flag){
		flag = 1;
		for(i = 0;i<length-1;i++){
			if(arr[i]>arr[i+1]){
				swap(&arr[i], &arr[i+1]);
				flag = 0;
			}
		}
	}


}
