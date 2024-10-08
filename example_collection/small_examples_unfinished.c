#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int * my_make_random_array(int size){
	//DEFINE ARRAY
	for(int i = 0; i < size; i++){
		my_array[i] = rand()%8;
	}
    //RETURN ARRAY
}

int main(void){
/* // EXAMPLE1 - pointer + 1 + dereference
int my_array[] = {3, 7, 4, 58};
int * my_ptr = my_array;
printf("At start: Pointer: %p; Value: %d\n", my_ptr, *my_ptr);

//DEREFERENCE THE VALUE OF THE SECOND VALUE PROPERLY

printf("After 1: Pointer: %p; Value: %d\n", my_ptr, *my_ptr);
*/


/* // EXAMPLE2 - pointers to a reallocated block
int* my_memory_block = (int*)malloc(10*sizeof(int));
int* my_memory_block_reference = my_memory_block;
for(int i = 0; i<10; i++) my_memory_block_reference[i] = i;
my_memory_block_reference[5] = 10;
for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, my_memory_block[i]);
for(int i = 0; i<10; i++) printf("My array value %d: %d\n", i, my_memory_block_reference[i]);

printf("\n");
//What happens after a realloc
my_memory_block = (int*)realloc(my_memory_block, 15*sizeof(int));
sleep(10);
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


}