#include <immintrin.h>
#define TYPE int
#define SHRINK_FACTOR 1.3
void swap(int *a, int *b);
void combsort(TYPE *arr, int length);
void simd_in_core_sort(TYPE *arr, int length);
//void  vector_cmpswap(vec_arr[i], vec_arr[i+gap]);

void  vector_cmpswap(__m128i *va, __m128i *vb);

void  vector_cmpswap_skew(__m128i *va, __m128i *vb);

