#include "sort.h"

//using sw simd instructions
#include <simd.h>


void simd_in_core_sort(int *arr, int length){

	/*********************
	load to the vector array.
	TODO
	*********************/
	int vec_num = length/4;
	int i=0;
	intv8 va[vec_num];
	for(i = 0; i < vec_num; i++){
		simd_load(va[i], &arr[4*i]);
	}
    


	int gap = vec_num/SHRINK_FACTOR;
	while(gap > 1){
	/**************************
		 straight compare
	 *************************/
		for(i = 0; i < vec_num - gap; i++){
			vector_cmpswap(va[i], va[i+gap]);
		}

	/*******************************
		skewed compare
		when i+gap exceeds vec_num.
	*******************************/
		for(i = vec_num-gap; i<num;i++){
			vector_cmpswap_skew(va[i], va[i+gap-vec_num]);
		}
		
		gap = gap/SHRINK_FACTOR;
	}//end of while


	int flag = 0;
	while(!flag){
		flag = 1;
		for(i = 0; i < vec_num - 1; i++){
			vector_cmpswap(va[i],va[i+1]);
			vector_cmpswap_skew(va[vec_num-1], va[0]);
			//TODO:flag = 0;
		}
	}

}
