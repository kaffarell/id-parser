#ifndef ID_PARSER_PARSER_H
#define ID_PARSER_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *file;

// Lists of id's in file
extern char* name_list[100];
extern char* value_list[100];


/*
Write int values to the speciefied identifier
 */
void write(char* identifier, int value);

/*
Reads all the id's in the file.
Attention, gets executed automatically!
 */
void read();

/*
Call this function to get integer of the specified
identifier.
 */
int valueof_int(char *id_input);

/*
Call this function to get a value as a string.
 */
char* valueof_string(char *id_input);

/*
Returns the value of identifier (id_input) as a float.
 */
float valueof_float(char *id_input);

/*
Gets used internally, not intendet to be used.
 */
int get_linecount(char* filename);

/*
Expects filename, file mode set to read (r) because the main file pointer
is only used to read files in read(), calls read() automatically.
*/
FILE init(char filename[64]);



#endif //ID_PARSER_PARSER_H
