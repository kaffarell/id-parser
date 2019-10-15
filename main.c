#include<stdio.h>
#include"parser.h"

int main(){
    int result;
    char* input;
    int value;

    FILE id;
    id = init("/home/gabriel/CLionProjects/id-parser/test.id");
    printf("input identifier: \n");
    //scanf("%s", input);
    printf("input value\n");
    //scanf("%d", &value);
    write("test", 5);
    printf("value of jake: %d\n", valueof_int("jake"));
    printf("value of name: %s\n", valueof_string("name"));
    printf("value of float: %f \n", valueof_float("float"));


    return 0;
}