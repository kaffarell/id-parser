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
    printf("value of id: %d\n", valueof_int("id"));


    return 0;
}