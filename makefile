OBJ=main.o combsort.o swap.o simd_in_core_sort.o vector_cmpswap.o vector_cmpswap_skew.o
CC=icc -O3
main:sort.h $(OBJ)
	$(CC) $(OBJ) -o main
main.o:sort.h
	$(CC) -c main.c
combsort.o:sort.h
	$(CC) -c combsort.c
swap.o:sort.h
	$(CC) -c swap.c
simd_in_core_sort.o:sort.h
	$(CC) -c simd_in_core_sort.c -msse2
vector_cmpswap.o:
	$(CC) -c vector_cmpswap.c -msse2
vector_cmpswap_skew.o:
	$(CC) -c vector_cmpswap_skew.c -msse2

clean:
	rm $(OBJ) main 1.txt

