#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <errno.h>
#include"parser.h"

char *name_list[];
char *value_list[];
int lines = 0;
char *filename_global;


FILE init(char filename[64]) {
    // Open file to read values in read() function
    file = fopen(filename, "rb");
    // Check if file has been opened
    if (file == NULL) {
        printf("wrong file\n");
        exit(0);
    }
    filename_global = filename;
    // Get total linecount of file
    lines = get_linecount(filename);
    // Set size of arrays according to linecount
    name_list[lines];
    value_list[lines];

    // Allocate space for arrays
    for (int i = 0; i < lines; i++) {
        name_list[i] = (char *) malloc(sizeof(char) * 10);
        value_list[i] = (char *) malloc(sizeof(char) * 10);
    }

    read();
}

void write(char* identifier, int value) {
    // File pointer to write whole array to file
    FILE *write;

    // Searches in array for identifier and replaces their value
    for (int i = 0; i < lines; i++) {
        if (strcmp(identifier, name_list[i]) == 0) {
            sprintf(value_list[i], "%d", value);
        }
    }
    // Goes in write mode and cleares file
    write = fopen(filename_global, "wb");

    // Test if file has been opened correctly
    if(write == NULL){
        printf("error opening file\n");
        exit(0);
    }

    // Write whole array to file
    for(int c = 0; c < lines; c++){
        fprintf(write, "%s = %s\n", name_list[c], value_list[c]);
    }
    fclose(write);

}

void read() {
    char *value = malloc(4);
    char *name = malloc(4);
    int equal_index = 0, c = 0, size = 10;
    char *string;

    // Set cursor to top
    fseek( file, 0, SEEK_SET );

    for (int a = 0; a < lines; a++) {
        getline(&string, (size_t *) &size, file);

        // Gets position of '='
        for (int i = 0; i < 10; i++) {
            if (string[i] == '=') {
                equal_index = i;
            }
        }
        // Gets name:
        // Copy substring before '=' to variable name
        strncpy(name, string, equal_index - 1);

        // Gets value:
        c = 0;
        while (c < 2) {
            value[c] = string[(equal_index + 3) + c - 1];
            c++;
        }
        value[c] = '\0';

        // Copy string to array with strncpy
        name_list[a] = strncpy(name_list[a], name, 5);
        value_list[a] = strncpy(value_list[a], value, 5);

        // Clearing arrays to not get appended pieces when using shorter name after longer name
        memset(&name[0], 0, sizeof(name));
        memset(&value[0], 0, sizeof(value));
    }
    fclose(file);



}

int valueof_int(char *id_input) {
    int char_number = 0, counter = 0, result = 0, a = 0;
    int *zahlen = (int *) malloc(sizeof(char) * 10);;

    for (int i = 0; i < lines; i++) {
        if (strcmp(id_input, name_list[i]) == 0) {
            // Convert number from char* to integer
            for (a = 0; a < 5; a++) {
                char_number = value_list[i][a];
                if ((int) char_number >= 48 && (int) char_number <= 57) {
                    // Checking if char is a integer trough ascii and assigning to variable
                    zahlen[a] = (int) char_number - 48;
                } else {
                    break;
                }
            }
            // Making the second number * 10 and add them to get integer
            counter = a;
            for (int c = 0; c < a; c++) {
                counter--;
                zahlen[c] = zahlen[c] * pow(10, counter);
            }
            // Sum all integer in array
            for (int c = 0; c < a; c++) {
                result += zahlen[c];
            }

            return result;
        }
    }
    return -1;
}

int get_linecount(char *filename) {
    int c = 0;
    lines = 0;
    lines++;

    // Get number of lines
    FILE *countline_file;
    countline_file = fopen("/home/gabriel/CLionProjects/id-parser/test.id", "r");

    if( countline_file == NULL ) {
        printf("Error %d \n", errno);
        perror("test.id");
    }

    while (1) {
        c = fgetc(countline_file);
        if (c == -1) {
            fclose(countline_file);
            return lines - 1;
        }
        if (c == 10) {
            lines++;
        }

    }
}

