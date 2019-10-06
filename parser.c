#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"parser.h"

char *name_list[];
char *value_list[];
int lines = 0;


FILE init(char *filename, char *mode) {
    name_list[get_linecount(filename)];
    value_list[get_linecount(filename)];
    lines = get_linecount(filename);
    // Allocate space for arrays
    for (int i = 0; i < lines; i++) {
        name_list[i] = (char *) malloc(sizeof(char) * 10);
        value_list[i] = (char *) malloc(sizeof(char) * 10);
    }



    // Open file to read values in read() function
    file = fopen(filename, mode);
    if (file == NULL) {
        printf("wrong file\n");
        exit(0);
    }
    printf("filename: %s, mode: %s \n", filename, mode);
    if (strcmp(mode, "r") == 0) {
        read();
    } else if (strcmp(mode, "w") == 0) {
        write();
    } else {
        printf("error");
    }
}

void write() {

}

void read() {
    char *value = malloc(4);
    char *name = malloc(4);
    int equal_index = 0, c = 0, size = 10;
    char *string;
    int bytes_read;


    for (int a = 0; a < lines; a++) {
        string = (char *) malloc(size);
        bytes_read = getline(&string, (size_t *) &size, file);

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
        bytes_read--;
        while (c < 2) {
            value[c] = string[(equal_index + 3) + c - 1];
            c++;
        }
        value[c] = '\0';

        // Copy string to array with strncpy!
        name_list[a] = strncpy(name_list[a], name, 5);
        value_list[a] = strncpy(value_list[a], value, 5);

        // Clearing arrays to not get appended pieces when using shorter name after longer name
        memset(&name[0], 0, sizeof(name));
        memset(&value[0], 0, sizeof(value));
    }
    fclose(file);

    /*test
    for(int i = 0; i < lines; i++){
        printf("name: %s, value: %s \n", name_list[i], value_list[i]);
    }
     */



}

int valueof_int(char *id_input) {
    int char_number, counter, result, a;
    int *zahlen;

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
    // Get number of lines
    FILE *fp = fopen(filename, "r");
    lines = 0;
    lines++;
    int c = 0;
    while (1) {
        c = fgetc(fp);
        if (c == -1) {
            fclose(fp);
            return lines - 1;
        }
        if (c == 10) {
            lines++;
        }

    }
}

