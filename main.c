#include<stdio.h>
#include"parser.h"

int main(){
    int result;
    char* input;
    int value;

    FILE id;
    id = init("/home/gabriel/CLionProjects/id_parser/test.id", "r");
    printf("input identifier: \n");
    //scanf("%s", input);
    printf("input value\n");
    //scanf("%d", &value);
    write("test", 5);


    return 0;
}