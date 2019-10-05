#ifndef ID_PARSER_PARSER_H
#define ID_PARSER_PARSER_H

#include<stdio.h>
#include<stdlib.h>

FILE *file;
extern char* name_list[5];
extern char* value_list[5];

void write();
void read();
int valueof_int(char *id_input);
int get_linecount(char* filename);
FILE init(char *filename, char *mode);




#endif //ID_PARSER_PARSER_H
