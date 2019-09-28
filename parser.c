#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"parser.h"


FILE init(char *filename, char *mode){
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

    //TODO: count lines and use that as line count
    for(int a = 0; a < 5; a++){
        int size = 10;
        char *string;
        int bytes_read;
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

        //FIXME: array assigned here is empty in other function
        name_list[a] = name;
        value_list[a] = value;
        printf("name: %s, value: %s\n", name, value);
    }


    for(int i = 0; i < 5; i++){
        printf("2name = %s, value = %s \n", name_list[i], value_list[i]);
    }
}

int valueof_int(char *id_input){
    int result = 0;

    //output array for test
    for(int i = 0; i < 5; i++){
        printf("name: %s\n", name_list[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("value: %s\n", value_list[i]);
        printf("%s = %s\n", name_list[i], id_input);
        /*if(strcmp(name_list[i], id_input)){
            result = value_list[i];
            return result;
        }*/
    }
}

