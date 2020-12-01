/*
 * The test file
 */

#include "elements.h"

int main()
{
	int arr_size = ARR_SIZE;
	int add_num = 10;
	
	InitialiseArray(arr_size);
	
	/* Putting values in the array:								 	*/
	/* Just put the number you want here []						 	*/
	/* Choose the right type, after the dot (string, integer, fl)	*/
	/* You can't add zero as an element!							*/
	elements[0].fl = 4.2;
	elements[1].fl = 6.7;
	strcpy(elements[2].string, "chapter");
	elements[3].integer = 12;
	elements[4].fl = 56.32;
		
	MainMenu(arr_size, add_num);
	
	return (0);
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
