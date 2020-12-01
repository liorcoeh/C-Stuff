/*
 * Creating a Logger
 */

#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#define MAX (1000000)


enum OPERA
{
	GETOUT,
	COUNT,
	ADDUP,
	ADDEND,
	ERASE
};

/* Defining a structures of three types */
struct logger
{
	char check[10];
	enum OPERA (*Compare)(char *str, char *filename);
	enum OPERA (*Operation)(char *str, char *filename);
};


/* Deletes a file if needs to */
enum OPERA Delete(char *str, char *filename);

enum OPERA Operation_Delete(char *str, char *filename);

/* Counts the lines in the file if needs to */
enum OPERA Count(char *str, char *filename);

enum OPERA Operation_Count(char *str, char *filename);

/* Closes the file and goes out if needs to*/
enum OPERA Exit(char *str, char *filename);

enum OPERA Operation_Exit(char *str, char *filename);

/* Adds the new information to the top of the file if needs to */
enum OPERA Addup(char *str, char *filename);

enum OPERA Operation_Addup(char *str, char *filename);

/* Adds the new information at the end of the file if nothing happened */
enum OPERA Addend(char *str, char *filename);

enum OPERA Operation_Addend(char *str, char *filename);


#endif /* SIMPLE_LOGGER_H */