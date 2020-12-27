/*
 * Variable Size Memory Allocator
 */

#ifndef VARIABLE_SIZE_MEMORY_ALLOCATOR_H
#define VARIABLE_SIZE_MEMORY_ALLOCATOR_H

#include <stddef.h> /* size_t */

typedef struct variable_size_memory_allocator vsa_t;

/*
 * VSA Init: Initializing the main allocated memory
 * Return: Pointer to the begining of the entire memory allocated by the user
 * Receive:
 * - Pointer to the begining of the allocated memory
 * - The size of the entire memory allocated
 * Time Complexity: O(1)
 */
vsa_t *VSAInit(void *memory, size_t seg_size);

/*
 * VSA Alloc: Allocates a new memory block for the user
 * Return: Pointer to the new memory block
 * Receive:
 * - Pointer to the begining of the entire memory
 * - The wanted size of the allocated block of memory
 * Time Complexity: O(n)
 */
void *VSAAlloc(vsa_t *pool, size_t block_size);

/*
 * VSA Free: Frees a block requested by the user
 * Receive: Pointer to the requested block
 * Time Complexity: O(1)
 */
void VSAFree(void *vsa_t);

/*
 * VSA Largest Block Available: Checks what is the largest block available
 * Return: The size of the largest block available
 * Receive: Pointer to the begining of the entire memory
 * Time Complexity: O(n)
 */
size_t VSALargestBlockAvailable(vsa_t *pool);

#endif /* VARIABLE_SIZE_MEMORY_ALLOCATOR_H */
















