/*
 * Variable Size Memory Allocator - test file
 */

#include <stdio.h>	/* printf() */
#include <stdlib.h> /* malloc(), free() */

#include "variable_size_memory_allocator.h"

#define GOOD

void GoodLuck();
void GoodJob();

int main()
{
	size_t total_size = 112;
	size_t first = 32;
	size_t second = 8;
	size_t third = 8;
	size_t forth = 16;
	size_t new_one = 24;
	int *block1;
	int *block2;
	int *block3;
	int *block4;
	
	void *memory = NULL;
	
	#ifdef GOOD
	GoodLuck();
	#endif

	memory = (void *)malloc(total_size);

	VSAInit(memory, total_size);
	
	printf("The largest block right after initialization is(96): ");
	printf("%ld\n", VSALargestBlockAvailable(memory));
	
	block1 = VSAAlloc(memory, first);
	block2 = VSAAlloc(memory, second);
	block3 = VSAAlloc(memory, third);
	block4 = VSAAlloc(memory, forth);
	
	printf("After allocating four blocks the largest block is(0): ");
	printf("%ld\n", VSALargestBlockAvailable(memory));
	
	*block1 = 32;
	*block2 = 8;
	*block3 = 8;
	*block4 = 16;
	
	printf("Block #4 is(16): %d\n", *block4);
	printf("Block #3 is(8): %d\n", *block3);
	printf("Block #2 is(8): %d\n", *block2);
	printf("Block #1 is(32): %d\n", *block1);
	
	VSAFree(block2);
	VSAFree(block3);
	VSAFree(block4);
	
	printf("After freeing three blocks the largest block is (16): ");
	printf("%ld\n", VSALargestBlockAvailable(memory));
	
	block2 = VSAAlloc(memory, new_one);
	
	*block2 = 1;
	
	printf("The new block is(1): %d\n", *block2);
	
	printf("After allocating one block larger than several free blocks\n");
	printf("the largest block is (16): %ld\n", VSALargestBlockAvailable(memory));
	
	free(memory);
	memory = NULL;
	
	#ifdef GOOD
	GoodJob();
	#endif
	
	return (0);
}

/******************************************************************************/
/******************************************************************************/

void GoodLuck()
{
	printf("\n");
	printf("  * * * *     * * * *     * * * *    * * * * 	\n");
	printf(" *       *   *       *   *       *   *       *	\n");
	printf(" *           *       *   *       *   *        *	\n");
	printf(" *  * * *    *       *   *       *   *        *	\n");
	printf(" *       *   *       *   *       *   *        *	\n");
	printf(" *       *   *       *   *       *   *       *	\n");
	printf("  * * * *     * * * *     * * * *    * * * *	\n\n");
	
	printf(" *           *       *    * * * *    *     *    \n");
	printf(" *           *       *   *       *   *   *     	\n");
	printf(" *           *       *   *           * *        \n");
	printf(" *           *       *   *           * *     	\n");
	printf(" *           *       *   *           *   *   	\n");
	printf(" *            *     *    *       *   *     *   	\n");
	printf(" * * * * *     *****      * * * *    *       *  \n");
	printf("************************************************\n\n");
}

/******************************************************************************/

void GoodJob()
{
	printf("\n");
	printf("************************************************\n");
	printf("  * * * *     * * * *     * * * *    * * * * 	\n");
	printf(" *       *   *       *   *       *   *       *	\n");
	printf(" *           *       *   *       *   *        *	\n");
	printf(" *  * * *    *       *   *       *   *        *	\n");
	printf(" *       *   *       *   *       *   *        *	\n");
	printf(" *       *   *       *   *       *   *       *	\n");
	printf("  * * * *     * * * *     * * * *    * * * *	\n\n");
	
	printf("         * * *    * * * *     * * * *     	\n");
	printf("            *    *       *   *       *   	\n");
	printf("            *    *       *   *       *   	\n");
	printf("      *     *    *       *   * * * *     	\n");
	printf("      *     *    *       *   *       *   	\n");
	printf("      *     *    *       *   *       *   	\n");
	printf("       * * *      * * * *     * * * *    	\n\n");
}


