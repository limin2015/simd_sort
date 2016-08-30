#include "sort.h"

//using  simd instructions
#include <immintrin.h>


void simd_in_core_sort(int *arr, int length){

	/*********************
    step 1:
	load to the vector array and sort within a vector.
	using a method in paper.
	*********************/

	//1.1 sort within a vector using combsort
	int i;
	int numofVec = length/4;
	int gap = numofVec*3;
	while(gap>1){
		for(i = 0; i<length-gap; i++)
			if(arr[i]>arr[i+gap])
				swap(&arr[i], &arr[i+gap]);
		gap = gap - numofVec;
	}
	//1.2 load
	__m128i vec_arr[numofVec];
	for(i = 0;i < numofVec;i++){
		vec_arr[i] = _mm_set_epi32(arr[i],arr[i+numofVec],arr[i+2*numofVec],arr[i+3*numofVec]);
	}
	//endof load
	
	/*************************
	 step 2:sorting vector  using combsort.
	****************************/

	//2.1	
/*
	 gap = numofVec/SHRINK_FACTOR;
	while(gap > 1){
		for(i = 0; i < numofVec - gap; i++){
			vector_cmpswap(&vec_arr[i], &vec_arr[i+gap]);
		}

		//skewed compare:	when i+gap exceeds vec_num.
		for(i = numofVec-gap; i<length; i++){
			vector_cmpswap_skew(&vec_arr[i], &vec_arr[i+gap-numofVec]);
		}
		
		gap = gap/SHRINK_FACTOR;
	}//end of while

	//2.2
	int flag = 0;
	while(!flag){
		flag = 1;
		for(i = 0; i < numofVec - 1; i++){
			vector_cmpswap(&vec_arr[i], &vec_arr[i+1]);
			vector_cmpswap_skew(&vec_arr[numofVec-1], &vec_arr[0]);
			//TODO:flag = 0;
		}
	}
	
*/
	/**************
	  step 3:store.
	 ******************/
	int temp[4];
	for(i = 0;i < numofVec;i++){
		_mm_store_si128((__m128i*)&temp[0], vec_arr[i]);
		arr[i] = temp[0];
		arr[i+numofVec] = temp[1];
		arr[i+2*numofVec] = temp[2];
		arr[i+3*numofVec] = temp[3];
	}

}
