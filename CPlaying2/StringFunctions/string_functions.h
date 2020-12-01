/*
 * Header file for string functions
 */

/* Gives the length of a string */
size_t Strlen(const char *str);

/* Checks if two strings are exactly the same */
int Strcmp(const char *str1, const char *str2);

/* Copies a string into another string */
char *Strcpy(const char *source, char *destenation);

/* Copies a part of a string into another one */
char *Strncpy(const char *source, char *destenation, size_t n);

/* Checks if two strings are the same, not case sensative */
int Strcasecmp(const char *str1, const char *str2);

/* Returns a pointer to the the first place a character 'ch' shows up */
char *Strchr(const char *str, int ch);

/* Duplicates a string */
char *Strdup(const char *str);

/* Connects two strings into a one string */
char *Strcat(const char *sourse, char *destination);

/* Connects a part of one string to another string */
char *Strncat(const char *source, char *destination, size_t n);

/* Returns a pointer to first place one string shows up fully in the other one */
char *Strstr(const char *serach, const char *find);







