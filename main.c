#include<stdio.h>
#include"parser.h"

int main(){
    int result;
    char* input;

    FILE id;
    id = init("/home/gabriel/CLionProjects/id_parser/test.id", "r");
    printf("input identifier: \n");
    scanf("%s", input);
    result = valueof_int(input);
    printf("value of id: %d \n", result);


    return 0;
}