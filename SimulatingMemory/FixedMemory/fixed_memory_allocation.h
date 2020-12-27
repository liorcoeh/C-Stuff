/*
 * Fixed Memory Allocation
 */

#ifndef FIXED_MEMORY_ALLOCATOR_H
#define FIXED_MEMORY_ALLOCATOR_H

#include <stddef.h> /* size_t */

typedef struct fixed_size_allocation fsa_t;

/*
 * FSA Suggest Size: Gives the actuall size of the memory to be allocated
 * Return: The size of the actuall memory to be allocated
 * Receive:
 * - Number of blocks requested by the user
 * - The block size requested by the user - the block size will be aligned to
 *	 WORD size
 * Time Complexity: O(1)
 */
size_t FSASuggestSize(size_t num_blocks, size_t block_size);

/*
 * FSA Init: Initializes the fixed size allocation memory
 * Return: Pointer to the begining of the memory
 * Receive:
 * - Pointer to the start of the alocated memory
 * - The suggest size for the memory
 * - The size of a single block - will be aligned to a WORD size
 * Time Complexity: O(n)
 */
fsa_t *FSAInit(void *memory, size_t seg_size, size_t block_size);

/*
 * FSA Alloc: Allocates each block when it's needed
 * Return: Pointer to the block
 * Receive: Pointer to the main fixed memory start
 * Time Complexity: O(1)
 */
void *FSAAlloc(fsa_t *fsa_pool);

/*
 * FSA Free: Frees a block requested by the user
 * Receive: Pointer to the requested block to be free
 * Time Complexity: O(1)
 */
void FSAFree(void *block_ptr);

/*
 * FSA Count Free: Counts how many free blocks there are in the fsa
 * Return: The amount of free blocks in the the fsa
 * Receive: Pointer to the main fixed memory
 * Time Complexity: O(n)
 */
size_t FSACountFree(const fsa_t *fsa_pool);

#endif /* FIXED_MEMORY_ALLOCATOR_H */












