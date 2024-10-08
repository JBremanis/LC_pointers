#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int * my_make_random_array(int size){
	//int my_array[size];
    int * my_array = (int*)malloc(sizeof(int)*size);
	for(int i = 0; i < size; i++){
		my_array[i] = rand()%8;
	}
	return my_array;
    //int * my_array_ptr = my_array;
    //return my_array_ptr;
}

int* my_int_generator(int range){
	int * ret_val = (int *)malloc(sizeof(int)); 
    *ret_val = rand()%range;
    return ret_val;
}

// my_ptr examples
int main(void){

/* // EXAMPLE1 - pointer + 1 + dereference
int my_array[] = {3, 7, 4, 58};
int * my_ptr = my_array;
printf("At start: Pointer: %p; Value: %d\n", my_ptr, *my_ptr);

int 
val = (unsigned long int)my_ptr++;
val = *(my_ptr++);
val = (unsigned long int)++my_ptr;
val = *(my_ptr)++;
val = *(my_ptr+1);
val = *(my_ptr)+1;

printf("After 1: Pointer: %p; Value: %d\n", my_ptr, *my_ptr);
*/

/* // EXAMPLE2 - pointers to a reallocated block - After texture example
int* my_memory_block = (int*)malloc(10*sizeof(int));
int* my_memory_block_reference = my_memory_block;
for(int i = 0; i<10; i++) my_memory_block_reference[i] = i;
my_memory_block_reference[5] = 10;
for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, my_memory_block[i]);
for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, my_memory_block_reference[i]);

printf("\n");

my_memory_block = (int*)realloc(my_memory_block, 15*sizeof(int));
//Defined behaviour
for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, my_memory_block[i]);
//Undefined behaviour
for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, my_memory_block_reference[i]);
*/

/* // Example 3 array self regenerates the random numbers generated
    int * arr = my_make_random_array(10);
    for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, arr[i]);
    sleep(39);
    for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, arr[i]);
*/

/* //Example 4 My random int generator
int* my_int_holder = my_int_generator(100);
printf("%d\n", *my_int_holder);
for(long long int i = 0; i<1000000; i++){
	my_int_holder = my_int_generator(100);
	printf("%d\t", *my_int_holder);
    if(i%10 == 0) printf("\n");
    //free(my_int_holder);
}
printf("\n");
sleep(60);
//Memory leak
*/
}