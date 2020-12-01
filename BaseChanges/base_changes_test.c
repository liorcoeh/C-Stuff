/*
 * The test file for base changing functions
 */

#include "base_changes.h"

int main()
{
	char str[] = "11A";
	char str2[] = "11A";
	char result[50] = {0};
	char result2[50] = {0};
	int from_base = 11;
	int num = 142;
	int to_base = 2;

	printf("%d\n", ToBaseDec(str, from_base));
	printf("%s\n", DecBaseToOthers(num, result , to_base));
	printf("%s\n", BaseToBase(str2, result2, from_base, to_base));
	
	return (0);
}