#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"parser.h"

char *name_list[5];
char *value_list[5];



FILE init(char *filename, char *mode){
    //allocate space for arrays
    for(int i = 0; i < 5; i++){
        name_list[i] = (char *)malloc(sizeof(char)*10);
        value_list[i] = (char *)malloc(sizeof(char)*10);
    }

    file = fopen(filename, mode);
    if(file == NULL){
        printf("wrong file\n");
        exit(0);
    }
    printf("filename: %s, mode: %s \n", filename, mode);
    if(strcmp(mode, "r") == 0){
        read();
    }else if(strcmp(mode, "w") == 0){
        write();
    }else{
        printf("error");
    }
}

void write(){

}

void read(){
    char *value = malloc(4);
    char *name = malloc(4);
    int counter = 0;
    int equal_index = 0;
    int c = 0;
    int size = 10;
    char *string;
    int bytes_read;

    //TODO: count lines and use that as line count
    for(int a = 0; a < 5; a++){
        string = (char *) malloc (size);
        bytes_read = getline (&string, (size_t *) &size, file);

        //gets position of '='
        for(int i = 0; i < 10; i++){
            if(string[i] == '='){
                equal_index = i;
            }
        }
        //gets name:
        //copy substring before '=' to variable name
        strncpy(name, string, equal_index-1);

        //gets value:
        c = 0;
        bytes_read--;
        while (c < 2) {
            value[c] = string[(equal_index+3)+c-1];
            c++;
        }
        value[c] = '\0';

        //copy string to array with strncpy!
        name_list[a] = strncpy(name_list[a], name, 5);
        value_list[a] = strncpy(value_list[a], value, 5);
    }



}

int valueof_int(char *id_input){
    int char_number;
    int *zahlen;
    int a;
    int result;

    for(int i = 0; i < 5; i++){
        if(strcmp(id_input, name_list[i]) == 0){
            for(a = 0; a < 5; a++){
                char_number = value_list[i][a];
                if((int)char_number >= 48 && (int)char_number <= 57){
                    zahlen[a] = (int)char_number - 48;
                } else{
                    break;
                }
            }

            int counter = a;
            for (int c = 0; c < a; c++) {
                counter--;
                zahlen[c] = zahlen[c] * pow(10, counter);
            }

            for(int c = 0; c < a; c++){
                result += zahlen[c];
            }

            return result;
        }
    }
    printf("no identifier found\n");
}

