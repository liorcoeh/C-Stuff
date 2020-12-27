/*
 * Fixed Memory Allocation - Functions definitions file
 */

#include <stdlib.h> /* malloc(), free() */
#include <assert.h> /* assert() */

#include "fixed_memory_allocation.h"

#define WORDSIZE (sizeof(void *))

/* FSA Header */
struct fixed_size_allocation
{
	size_t block_size;
	size_t num_blocks;
	size_t next_free;
};

/* Each block header */
typedef struct block_header
{
	size_t next_free;
}block_t;

/*****************************************************************************/

/*
 * Swap: Help function for the FSAAlloc and FSAFree functions. Swaps to size_t
 * Reveive: Two pointer to size_t variables
 * Static function, only for using here
 */
static void Swap(size_t *a, size_t *b);

/*****************************************************************************/

size_t FSASuggestSize(size_t num_blocks, size_t block_size)
{
	size_t reminder = block_size % WORDSIZE;
	
	assert(num_blocks);
	assert(block_size);
	
	if (0 != reminder)
	{
		block_size += (WORDSIZE - reminder);
	}
	
	return (sizeof(fsa_t) + num_blocks * (sizeof(block_t) + block_size));
}

/*****************************************************************************/

fsa_t *FSAInit(void *memory, size_t seg_size, size_t block_size)
{
	size_t i = 0;
	size_t reminder = block_size % WORDSIZE;
	size_t size = 0;
	size_t blocks_num = 0;
	char *offset = (char *)memory;	/* Used for moving one byte at a time */
	size_t abs_off = 0;		/* Absullute offset */
	fsa_t *new_fsa = NULL;
	block_t *block_ptr = NULL;
	
	assert(memory);
	
	new_fsa = memory;	/* Putting fsa at the start of the pool  */
	block_ptr = memory;	/* Making a block_ptr point for block_ts */
	
	/* Getting the actual block size and number of blocks */
	if (0 != reminder)
	{
		block_size += (WORDSIZE - reminder);
	}
	
	blocks_num = (seg_size - sizeof(fsa_t)) / (sizeof(block_t) + block_size);
	
	/* Initializing the fsa_t */
	new_fsa->block_size = block_size;
	new_fsa->num_blocks = blocks_num;
	new_fsa->next_free = sizeof(fsa_t);
	
	abs_off = new_fsa->next_free;
	
	/* Initializing all the block_ts except the last one */
	for (i = 0; i < blocks_num - 1; ++i)
	{
		offset = (char *)new_fsa;
		offset += abs_off;
		block_ptr = (block_t *)offset;
		block_ptr->next_free = abs_off + sizeof(block_t) + size;
		abs_off += (size + sizeof(block_t));
	}
	
	/* Initializing the last block_t to be 0 */
	offset = (char *)new_fsa;
	offset += abs_off;
	block_ptr = (block_t *)offset;
	block_ptr->next_free = 0;

	return (new_fsa);	
}

/*****************************************************************************/

void *FSAAlloc(fsa_t *fsa_pool)
{
	block_t *block_ptr = NULL;
	char *offset = NULL;
	
	assert(fsa_pool);
	
	offset = (char *)fsa_pool + fsa_pool->next_free;
	block_ptr = (block_t *)offset;
	
	if (0 == fsa_pool->next_free)
	{
		printf("Segmentaion Fault\n");
		
		return (NULL);
	}

	Swap(&fsa_pool->next_free, &block_ptr->next_free);
	
	/* The 1 is equal a sizeof block_t */
	return (block_ptr + 1);
}

/*****************************************************************************/

void FSAFree(void *block_ptr)
{
	fsa_t *pool = NULL;
	char *offset = NULL;
	block_t *current_block = NULL;
	
	assert(block_ptr);
	
	current_block = (block_t *)block_ptr - 1;
	offset = (char *)current_block - current_block->next_free;
	pool = (fsa_t *)offset;
	
	Swap(&pool->next_free, &current_block->next_free);
}

/*****************************************************************************/

size_t FSACountFree(const fsa_t *fsa_pool)
{
	size_t count_free = 0;
	size_t offset = 0;
	block_t *block_ptr = NULL;
	char *offset_ptr = NULL;
	
	offset = fsa_pool->next_free;
	
	/* As long as the next_free isn't zero keep running */
	while (0 != offset)
	{
		offset_ptr = (char *)fsa_pool;
		offset_ptr += offset;
		block_ptr = (block_t *)offset_ptr;
		offset = block_ptr->next_free;
		
		++count_free;
	}
	
	return (count_free);
}
/******************************************************************************/

static void Swap(size_t *a, size_t *b)
{
	size_t temp = *a;
	*a = *b;
	*b = temp;
}

















