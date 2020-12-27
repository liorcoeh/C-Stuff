/*
 * Fixed Memory Allocation - Test file
 */

#include <stdio.h>	/* printf() */
#include <stdlib.h> /* malloc(), free() */

#include "fixed_memory_allocation.h"

void GoodLuck();
void GoodJob();

int main()
{
	size_t num_blocks = 3;
	size_t block_size = 30;
	size_t size = 0;	
	char *block1;
	char *block2;	
	int *block3;	
	void *pool = NULL;

	GoodLuck();

	size = FSASuggestSize(num_blocks, block_size);
	printf("The total size should be is %ld bytes\n\n", size);
	pool = (void *)malloc(size);
	
	FSAInit(pool, size, block_size);
	
	printf("The amount of free blocks at start(3): %ld\n", FSACountFree(pool));
	
	block1 = FSAAlloc(pool);
	block2 = FSAAlloc(pool);
	block3 = FSAAlloc(pool);
	
	printf("The amount of free blocks after three alocks(0): ");
	printf("%ld\n\n", FSACountFree(pool));
	
	block1 = "Hey Yaacov";
	block2 = "Hang in there man, you can do it!!!";
	*block3 = 123456789;
	
	printf("%s\n", block1);
	printf("%s\n", block2);
	printf("%d\n", *block3);
	
	FSAFree(block3);

	printf("The amount of free blocks, after one free(1): ");
	printf("%ld\n\n", FSACountFree(pool));
	
	free(pool);
	pool = NULL;
	
	GoodJob();
	
	return (0);
}

/******************************************************************************/
/******************************************************************************/

void GoodLuck()
{
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



