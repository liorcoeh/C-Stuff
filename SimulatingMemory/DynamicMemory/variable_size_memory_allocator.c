/*
 * Variable Size Memory Allocator - Functions definitions file
 */

#include <assert.h>	/* assert() */
#include <unistd.h>	/* ssize_t	*/

#include <stdlib.h> /* abs() */

#include "variable_size_memory_allocator.h"

#define WORDSIZE (sizeof(void *))
#define MAX_SIZE (2147483647)
#define VALID (2810198228910182)
/*#define DO_DEBUG*/

typedef struct variable_size_memory_allocator
{
	ssize_t block_size; /* Positive value means free, negative means not free */
#ifdef DO_DEBUG
	long valid;
#endif /* DO_DEBUG */
};

/*****************************************************************************/

vsa_t *VSAInit(void *memory, size_t seg_size)
{
	vsa_t *base_vsa = NULL;
	vsa_t *end_vsa = NULL;
	char *offset = NULL;
	size_t reminder = seg_size % WORDSIZE;
	
	assert(memory);
	
	offset = (char *)memory;
	offset += (seg_size - sizeof(vsa_t) - reminder);
	base_vsa = memory;
	end_vsa = (vsa_t *)offset;
		
	base_vsa->block_size = seg_size - 2 * (sizeof(vsa_t)) - reminder;
	end_vsa->block_size = MAX_SIZE;
	
	#ifdef DO_DEBUG
	base_vsa->valid = VALID;
	end_vsa->valid = VALID;
	#endif /* DO_DEBUG */

	return (base_vsa);
}

/*****************************************************************************/

void *VSAAlloc(vsa_t *pool, size_t block_size)
{
	char *offset = NULL;
	vsa_t *free_vsa = NULL;
	vsa_t *next_vsa = NULL;
	size_t free_space = 0;
	
	assert(pool);
	
	if (0 != block_size % WORDSIZE)
	{
		block_size += (WORDSIZE - (block_size % WORDSIZE));
	}	
	
	offset = (char *)pool;
	free_vsa = pool;
	next_vsa = pool;

	while (MAX_SIZE != free_vsa->block_size)
	{
		free_space += next_vsa->block_size;
		
		/* In case the block is not free */
		if (0 > next_vsa->block_size)
		{
			free_space = 0;
			offset += (next_vsa->block_size * -1) + sizeof(vsa_t);
			next_vsa = (vsa_t *)offset;
			free_vsa = next_vsa;
		}
		
		/* In case it is free but not enough space */
		else if (block_size > free_space)
		{
			free_space += sizeof(vsa_t);
			offset += next_vsa->block_size + sizeof(vsa_t);
			next_vsa = (vsa_t *)offset;
		}
		
		/* When there is enough space to alloc */
		else
		{
			offset = (char *)free_vsa;
			offset += (sizeof(vsa_t) + block_size);
			next_vsa = (vsa_t *)offset;
			
			/* In case a header falls on an older header */
			if (0 != next_vsa->block_size % WORDSIZE)
			{
				next_vsa->block_size = free_space - block_size - sizeof(vsa_t);
			}
			free_vsa->block_size = block_size * -1;

			return (free_vsa + 1);
		}
		
		/* In case we got to the last block but it's not enough */
		if (MAX_SIZE == next_vsa->block_size)
		{
			return (NULL);
		}
	}
	
	return (NULL);
}

/*****************************************************************************/

void VSAFree(void *block_ptr)
{
	vsa_t *current_block = NULL;
	
	assert(block_ptr);
	
	current_block = (vsa_t *)block_ptr - 1;
	current_block->block_size *= -1;
}

/*****************************************************************************/

size_t VSALargestBlockAvailable(vsa_t *pool)
{
	vsa_t *current_block = NULL;
	char *offset = NULL;
	ssize_t max_size = 0;
	
	assert(pool);
	
	offset = (char *)pool;
	current_block = pool;
	
	while (MAX_SIZE != current_block->block_size)
	{
		/* Comparing max_size to each block size */
		if (max_size <= current_block->block_size)
		{
			max_size = current_block->block_size;
		}
		
		offset += sizeof(vsa_t) +  (abs(current_block->block_size));
		/* Moving the block forward */
		current_block = (vsa_t *)offset;	
	}
	return (max_size);
}





















