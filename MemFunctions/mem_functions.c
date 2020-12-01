/****************************************************************************
* File Name: MemFuncs.c														*
* Writer: Lior Cohen														*
* Date: 23/02/2020														    *
* Purpose: Implemetation of the functions memset, memcpy and memmove		*
* Code Reviwer: Anat Wax													*
*****************************************************************************/

#include <stdint.h>

#include "mem_functions.h"

#define GETPADDING(adress) ((size_t)(adress) % (8))

typedef unsigned char byte;
typedef size_t word;

void *Memset(void *str, int c, size_t n)
{
	word *str_word_p = NULL;		/* Pointer to str as words */
	byte *str_byte_p = (byte *)str; /* Pointer to str as bytes */
	word c_word = c & 0xff;		/* Mask to take only the first 8 bytes of c */
	byte c_byte = c & 0xff;		/* Mask to take only the first 8 bytes of c */
	size_t tail = 0;			/* Will take the tail of the word */
	int i = 0;
	int word_size = sizeof(word);

	/* Duplicating the char to a word: */
	for (i = 3; (1 << i) < (word_size * 8); ++i)
	{
		c_word |= c_word << (1 << i);
	}

	/* Check the alignment - if the adress divides by the word_size and */
	/* n is not 0 - assign c_byte to each byte:							*/
	while (((word)str_byte_p & (word_size - 1)) && (0 != n))
	{
		*str_byte_p = c_byte;
		--n;
		++str_byte_p;
	}

	/* Get the tail - by checking the bits of n and (word_size - 1) */
	tail = n & (word_size - 1);
	
	/* Assign new word-size pointer to str */
	str_word_p = (word *)str_byte_p; 

	/* Loop to duplicate the word-size c in str, using what left from n */
	for (n >>= i - 3; n > 0; ++str_word_p, --n)
	{
		*str_word_p = c_word;
	}

	/* Assign current str location to str_byte_pointer */
	str_byte_p = (byte *)str_word_p;
	
	/* Add the chars of the tail */
	for (; tail != 0; --tail, str_byte_p++)
	{
		*str_byte_p = c_byte;
	}

	return (str);
}

void *Memcpy(void *dest, const void *src, size_t n)
{
	word *dest_word_p = (word *)dest; /* Pointer to dest as words */
	word *src_word_p = (word *)src;	  /* Pointer to src as words  */
	byte *dest_byte_p = (byte *)dest; /* Pointer to dest as bytes */
	byte *src_byte_p = (byte *)src;	  /* Pointer to src as bytes  */
	
	size_t tail = 0; /* Will take the tail of the word */
	int word_size = sizeof(word);

	/* Check the alignment - if the adress of dest divides by the word_size */
	/* and n is not 0 - assign chars of src to each byte:					*/
	while (((word)dest_byte_p & (word_size - 1)) && n)
	{
		*dest_byte_p = *src_byte_p;
		--n;
		++dest_byte_p;
		++src_byte_p;
	}

	/* Get the tail - by checking the bits of n and (word_size - 1) */
	tail = n & (word_size - 1);

	/* Make a new word-size pointer to dest */
	dest_word_p = (word *)dest_byte_p;
	
	/* Make a new word-size pointer to src */
	src_word_p = (word *)src_byte_p; 

	/* Main loop to duplicate the word-size chunks of dest to src,		*/ 
	/* using what left from n 											*/
	for (n /= word_size; n > 0; --n, ++src_word_p, ++dest_word_p)
	{
		*dest_word_p = *src_word_p;
	}

	/* Assign current strings location to the byte pointers */
	dest_byte_p = (byte *)dest_word_p;
	src_byte_p = (byte *)src_word_p;

	/* Add the chars of the tail */
	for (;tail != 0; --tail, ++dest_byte_p, ++src_byte_p)
	{
		*dest_byte_p = *src_byte_p;
	}

	return (dest);
}

void *Memmove(void *dest, const void *src, size_t n)
{
	/* If the memory location of src is greater than dest - do Memcpy */
	/* There is no danger of overlapping */
	if ((word)dest < (word)src) 
	{
		return (Memcpy(dest, src, n));
	}
	
	/* If the dest and src are aligned - try to move in word chuncks */
	if ((0 == (word)dest % sizeof(word)) && (0 == (word)src % sizeof(word)))
	{
		word *dest_word_p = (word *)dest; /* Pointer to dest as words */
		word *src_word_p = (word *)src;	  /* Pointer to src as words  */
		byte *dest_byte_p = (byte *)dest; /* Pointer to dest as bytes */
		byte *src_byte_p = (byte *)src;	  /* Pointer to src as bytes  */
		
		size_t tail = 0; /* Will take the tail of the word */
		int word_size = sizeof(word);
 		
 		/* Get the pointers to their last byte: */
 		dest_byte_p += (n - 1);
 		src_byte_p += (n - 1);
 		
 		/* Get the tail - by checking the bits of n and (word_size - 1) */ 
 		tail = n & (word_size - 1);
 		
 		/* Copy the chars of the tail */
		for (;tail != 0; --tail, --dest_byte_p, --src_byte_p)
		{
			*dest_byte_p = *src_byte_p;
		}
 		
 		/* Loop to duplicate the word-size chunks of dest to src, */
		/* from the last to the first 							  */
		for (n /= word_size; n > 0; --n)
		{
			/* The reason we copy index n-1 and test n>0 is that  */
			/* n is unsigned -- so testing n>=0 doesn't work.     */
			dest_word_p[n-1] = src_word_p[n-1];
		}
	}
	
	else 
	{
		/* If they are not aligned - copy byte by byte from the end */
		byte *dest_byte_p = dest;
		const byte *src_byte_p = src;
 
		for (; n > 0; n--) 
		{
			dest_byte_p[n - 1] = src_byte_p[n - 1];
		}
	}
 
	return dest;
}
